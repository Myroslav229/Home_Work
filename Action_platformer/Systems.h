#pragma once
#include <tuple>
#include <iostream>
#include "Global.h"
#include "Entities.h"
static std::set<int> dead;
struct SystemBase {
  
  SystemBase(Entities & entities): entities{entities} {};
  void each_entity(auto && f) {
    for(auto & entity_variant: entities) {
      std::visit([&](auto & entity){
        f(entity_variant.first, entity.components);
      }, entity_variant.second);
    }
  }

  void get_entity(auto && f, int id) {
    if (!entities.count(id)) return;
    std::visit([&](auto & entity){ f(entity.components); }, entities[id]);
  }
  void remove_entity(int id) {
      if (!entities.count(id)) return;
      entities.erase(id);
  }
  template <typename T> int create_entity(Vector2D position) {
      ++global::id;
      int id = global::id;
      entities[global::id] = T{ position };
      return global::id;
  }
protected:
  Entities & entities;
};

namespace System {

	struct Fall: private SystemBase {
    Fall(auto & entities): SystemBase{entities} {}
		void operator()(float dt) {
      each_entity([&](int id, auto & components){
        if constexpr (checkAllOf<TypePack<State, Direction, Velocity, Mass>, decltype(components)>()) {
          auto [state, direction, velocity] = getCmpts<State, Direction, Velocity>(components);
            direction.y = 1.f;
            velocity.y += 653.33f * dt;
        }
      });
    }
  };

    struct Move : private SystemBase {
    Move(auto & entities): SystemBase{entities} {}
		void operator()(float dt) {
      each_entity([&](int, auto & components){
        if constexpr (checkAllOf<TypePack<Transform, Direction, Velocity>, decltype(components)>()) {
          auto [transform, direction, velocity] = getCmpts<Transform, Direction, Velocity>(components);
          if (direction.x != 0) {
              direction.currentDir = direction.x;
          }
            transform.tempPosition.y = transform.position.y ;
            transform.position.x += direction.x * velocity.x * dt;
            transform.position.y += direction.y * velocity.y * dt;
        }
      });
		}
	};

    struct AnimationS : private SystemBase {
        AnimationS(auto& entities) : SystemBase{ entities } {}
        void operator()(float dt) {
            each_entity([&](int, auto& components) {
                if constexpr (checkAllOf<TypePack<Sprite, Direction>, decltype(components)>() &&
                    checkAllOfBase<Animation, decltype(components)>()) {
                    auto [sprite, direction] = getCmpts<Sprite, Direction>(components);
                    
                    getCmptsFromBase<Animation>([&](auto& animation) {
                        auto [frame, frameTime, loop] = animation.pack[animation.currentName];
                        animation.currentTime += dt;
                        if (animation.isEnabled) {
                            if (frame == 0) {
                                sprite.setFrame(animation.currentName, direction.currentDir);
                            }
                            else {
                                sprite.setFrame(animation.currentName + std::to_string(animation.currentFrame), direction.currentDir);
                            }
                            if (animation.currentFrame >= frame) {
                                animation.currentFrame = 0;
                                if (!loop) animation.stop();
                            }
                            else {
                                if (animation.currentTime >= frameTime) {
                                    ++animation.currentFrame;
                                    animation.currentTime = 0;
                                }
                                if (direction.x == 0) {
                                    animation.currentFrame = 0;
                                }
                            }

                        }
                    }, components);
                }
            });
        }
    };

	struct InputS: private SystemBase {
    InputS(auto & entities): SystemBase{entities} {}
		void operator()(float) {
      each_entity([&](int, auto & components){
        if constexpr (checkAllOf<TypePack<Direction, Input, Jump, Shoot>, decltype(components)>()) {
          auto [direction, input, jump, velocity, shoot] = getCmpts<Direction, Input, Jump, Velocity, Shoot >(components);
          direction.x = 0;
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            direction.x = 1.f;
            velocity.x = velocity.start.x;
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            direction.x = -1.f;
            velocity.x = velocity.start.x;
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            jump.sendDash = 1 ;
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
             shoot.sendShoot = true;
          }
        }
      });
		}
	};

	struct CollisionS: private SystemBase {
    CollisionS(auto & entities): SystemBase{entities} {}
		void operator()(float) {
			each_entity([&](auto fst_id, auto & fst_components){
				each_entity([&](auto snd_id, auto & snd_components){
					if (fst_id == snd_id) return;
          if constexpr (checkAllOf<TypePack<Transform, Collision>, decltype(fst_components)>()) {
            if constexpr (checkAllOf<TypePack<Transform, Collision>, decltype(snd_components)>()) {
              auto [tsfmA, collA] = getCmpts<Transform, Collision>(fst_components);
              auto [tsfmB, collB] = getCmpts<Transform, Collision>(snd_components);
              auto boxA = collA.box;
              auto boxB = collB.box;
              auto posA = tsfmA.position;
              auto posB = tsfmB.position;
              
              if (posA.x < posB.x + boxB.w && posA.x + boxA.w > posB.x &&
                  posA.y < posB.y + boxB.h && posA.y + boxA.h > posB.y) {
                  for (auto& group : collA.collWith) {
                      if (collB.group == group) {
                          collB.callback.insert(fst_id);
                      }
                  }
                  for (auto& group : collB.collWith) {
                      if (collA.group == group) {
                          collA.callback.insert(snd_id);
                      }
                  }
              }
              else {
                  collA.callback.erase(snd_id);
                  collB.callback.erase(fst_id);
              }
 
            }
          }
				});
			});
    }
  };
    
	struct Draw: private SystemBase {
    Vector2D cam_pos;
    Draw(auto & entities): SystemBase{entities} {}
		void operator()(float) {
        each_entity([&](auto id, auto & components){
            if constexpr (checkAllOf<TypePack<Transform, Sprite>, decltype(components)>()) {
              auto [transform, sprite] = getCmpts<Transform, Sprite>(components);
              if constexpr (checkAllOf<Camera, decltype(components) >()) {
                  cam_pos.x = transform.position.x - 512;
                  cam_pos.y = transform.position.y - 512;
              }
              sprite.element.setPosition(transform.position.x - cam_pos.x, transform.position.y- cam_pos.y);
              window.draw(sprite.element);
        }
      });
		}
	};

    struct UI : private SystemBase {
        float promtTime{};
        UI(auto& entities) : SystemBase{ entities } {}
        void operator()(float dt) {
            if (!global::gameOver) {
                each_entity([&](auto id, auto& components) {
                    if constexpr (checkAllOf<TypePack<Camera, Health>, decltype(components)>()) {
                        auto [health] = getCmpts<Health>(components);
                        sf::RectangleShape healthbar{{320 * (health.point / health.defaultHealth), 32}};
                        healthbar.setPosition(50, 50);
                        healthbar.setFillColor(sf::Color::Red);
                        window.draw(healthbar);
                        if constexpr (checkAllOf<Collision, decltype(components)>()) {
                            auto [collision] = getCmpts<Collision>(components);
                            for (auto snd_id : collision.callback) {
                                get_entity([&](auto& snd_components) {
                                    if constexpr (checkAllOf<Collision, decltype(snd_components)>()) {
                                        if (std::get<Collision>(snd_components).group == CollisionGroup::Sensor) {
                                            window.draw(out("You win", 50, 450, 400));
                                        }
                                    }
                                }, snd_id);
                            }
                        }
                        promtTime += dt;
                        if (promtTime <= 20) {
                            window.draw(out("pres F for shoot", 20, 10, 10));
                        }
                    }

                    });
            }
            else {
                window.draw(out("You Lose", 50, 450, 400));
            }
            
        }
    };

	struct AttackS: private SystemBase {
    AttackS(auto & entities): SystemBase{entities} {}
		void operator()(float) {
			each_entity([&](int id, auto & components){
        if constexpr (checkAllOf<TypePack<Collision, Attack>, decltype(components)>()) {
          auto [collision, attack] = getCmpts<Collision, Attack>(components);
          if (collision.group == CollisionGroup::Bullet && !collision.callback.empty()) {
              dead.insert(id);
              std::cout << "up" << std::endl;
          }
          for (auto snd_id : collision.callback) {
              get_entity([&](auto& snd_components) {
                  if constexpr (checkAllOf<Health, decltype(snd_components)>()) {
                      std::get<Health>(snd_components).point -= attack.damage;
                      if (attack.damage > 0) {
                          if constexpr (checkAllOf<DamageDiscarding, decltype(snd_components)>()) {
                              auto [dmgDiscarding] = getCmpts<DamageDiscarding>(snd_components);
                              dmgDiscarding.sendDash = true;
                          }
                      }
                      else {
                          if constexpr (checkAllOf<Camera, decltype(snd_components)>()) {
                              std::get<Health>(snd_components).point -= attack.damage;
                              if (collision.group == CollisionGroup::PickUp){
                                  dead.insert(id);
                              }
                          }
                      }
                  }
            }, snd_id);
          }
        }
			});
		}
	};
	
	struct Static: private SystemBase {
    Static(auto & entities): SystemBase{entities} {}
		void operator()(float) {
			each_entity([&](int, auto & components){
					if constexpr (checkAllOf<TypePack<Transform, Collision, State>, decltype(components)>()) {
            auto [tsfmA, collA, stateA] = getCmpts<Transform, Collision, State>(components);
            if(collA.group == CollisionGroup::Static ){
                for (auto snd_id : collA.callback) {
                    get_entity([&](auto& snd_components) {
                        if constexpr (checkAllOf<TypePack<Transform, Collision, Direction, State, Velocity>, decltype(snd_components)>()) {
                            auto [tsfmB, collB, direction, state, velocity] = getCmpts<Transform, Collision, Direction, State, Velocity>(snd_components);
                            auto boxA = collA.box;
                            auto boxB = collB.box;
                            auto& posA = tsfmA.position;
                            auto& posB = tsfmB.position;
                            auto distX = posA.x - posB.x;
                            auto distY = posA.y - posB.y;

                            auto intersectX = 0.f;
                            auto intersectY = 0.f;
                            if (distX >= 0) { intersectX = boxB.w - distX; }
                            else if (distX < 0) { intersectX = boxA.w + distX; }
                            if (distY > 0) { intersectY = boxB.h - distY; }
                            else if (distY < 0) { intersectY = boxA.h + distY; }
                            float multX = 1.f;
                            float multY = 1.f;
                            state.isOnGround = false;
                            if (sqrt(intersectX * intersectX) < sqrt(intersectY * intersectY)) {
                                multX = 25.f;
                            }
                            if (sqrt(multX * intersectX * intersectX) < sqrt(multY * intersectY * intersectY)) {
                                if (distX > 0) {
                                    posB.x += distX - boxB.w;
                                    velocity.x = 0;
                                }
                                if (distX < 0) {
                                    posB.x += distX + boxA.w;
                                    velocity.x = 0;
                                }
                            }
                            else {
                                if (distY > 0) {
                                    velocity.y = 0;
                                    posB.y += distY - boxB.h + velocity.y / 60;
                                    state.isOn—eiling = false;
                                }

                                if (distY < 0) {
                                    velocity.y = 0;
                                    posB.y += distY + boxA.h + velocity.y / 60;
                                    state.isOn—eiling = true;
                                }
                            }
                        }
                        }, snd_id);
                      }
                    }	                   
				}
			});
		}
        
	};
    
	struct DashS: private SystemBase {
    DashS(auto & entities): SystemBase{entities} {}
		void operator()(float dt) {
      each_entity([&](int, auto & components){
        if constexpr (checkAllOf<TypePack< Velocity, Direction, State>, decltype(components)>()) {
            if constexpr (checkAllOfBase<Dash, decltype(components)>()) {
                getCmptsFromBase<Dash>([&](auto& dash) {
                    auto [velocity, direction, state] = getCmpts< Velocity, Direction, State>(components);
                    if (dash.needGround && !state.isOnGround) {
                        dash.sendDash = false;
                    }
                    if (dash.currentTime >= dash.cooldown) {
                        dash.currentTime = 0;
                        dash.isOnDash = false;
                        dash.sendDash = false;
                        velocity.y = 0;
                        if constexpr (checkAllOf<TypePack<Animation>, decltype(components)>()) {
                            auto [animation] = getCmpts<Animation>(components);
                        }
                    }
                    if (dash.isOnDash) {
                        dash.currentTime += dt;
                    }
                    if (dash.sendDash && dash.currentTime < dash.cooldown) {
                        dash.isOnDash = true;
                        if constexpr (checkAllOfBase<TypePack<Animation>, decltype(components)>()) {
                            auto [animation] = getCmpts<Animation>(components);
                        }
                        state.isOnGround = false;
                        direction.y = -1;
                            velocity.y = dash.y - 653.33f * dt;
                        if (dash.x != 0) {
                            if (direction.x == 0) {
                                direction.x = direction.currentDir;
                            }
                            velocity.x = dash.x ;
                        }
                    }
                }, components);
            }
          
        }
      });
		}
	};
    struct EnemyLogicS: private SystemBase {
        EnemyLogicS(auto& entities) : SystemBase{ entities } {}
        void operator()(float) {
            each_entity([&](int, auto& components) {
                if constexpr (checkAllOf<TypePack<State, Collision, EnemyLogic, Transform, Attack, Shoot, Jump, Velocity>, decltype(components)>()) {
                    auto [state, collA, logic, tsfmA, direction, attack, shoot, jump, velocity] = getCmpts<State, Collision, EnemyLogic, Transform, Direction, Attack, Shoot, Jump, Velocity>(components);
                   
                        each_entity([&](auto snd_id, auto& snd_components) {
                            if constexpr (checkAllOf<TypePack<Transform, Collision, Camera>, decltype(snd_components)>()) {
                                auto [tsfmB, collB] = getCmpts<Transform, Collision>(snd_components);
                                
                                auto boxA = collA.box;
                                auto boxB = collB.box;
                                auto posA = tsfmA.position;
                                auto posB = tsfmB.position;
                                direction.x = 0;
                                
                                if (!state.isOnGround) {
                                    velocity.x = velocity.start.x / 3;
                                }
                                else {
                                    velocity.x = velocity.start.x;
                                }
                                if(posA.y < posB.y + boxB.h && posA.y + boxA.h > posB.y)
                                if (sqrt(pow((posA.x - posB.x), 2)) < 640.f) {
                                    logic.seePlayer = true;
                                }
                                if (posA.y < posB.y + boxB.h && posA.y + boxA.h > posB.y && logic.seePlayer) {
                                    
                                    shoot.sendShoot = true;
                                    
                                    
                                }
                                else if (posA.y + boxA.h > posB.y && logic.seePlayer) {
                                    jump.sendDash = true;
                                }
                                if (posB.x + boxB.w  < posA.x + boxA.w - 64 && logic.seePlayer) {
                                    
                                    direction.x = -1;
                                }
                                else if (posB.x + boxB.w  > posA.x + boxA.w + 64 && logic.seePlayer) {
                                    direction.x = 1;
                                }
                            }
                            });
                       
                }
                });
        }
    };

    struct HealthCheck :private SystemBase {
        HealthCheck(auto& entities) : SystemBase{ entities } {}
        void operator()(float) {
            each_entity([&](int id, auto& components) {
                if constexpr (checkAllOf<Health, decltype(components)>()) {
                    auto [health] = getCmpts<Health>(components);
                    if (health.point <= 0) {
                        if constexpr (checkAllOf<Camera, decltype(components)>()) {
                            global::gameOver = true;
                        }
                        dead.insert(id);
                    }
                    if (health.point > health.defaultHealth) {
                        health.point = health.defaultHealth;
                    }
                }
                });
        }
    };

    struct Death :private SystemBase {
       
        Death(auto& entities) : SystemBase{ entities } {}
        void operator()(float) {
            for (auto id : dead) {
                remove_entity(id);
            }
            dead.clear();
        }
    };

    struct IsOnGround : private SystemBase {
        IsOnGround(auto& entities) : SystemBase{ entities } {}
        void operator()(float) {
            each_entity([&](int id, auto& components) {
                if constexpr (checkAllOf<TypePack<Collision, Transform, State>, decltype(components)>()) {
                    auto [collision, transform, state] = getCmpts<Collision, Transform, State>(components);
                    if (transform.isStanding() && !state.isOn—eiling) {
                        state.isOnGround = true;
                    }
                    else {
                        state.isOnGround = false;
                    }
                }
                });
        }
    };


    struct AnimationChose : private SystemBase {
        AnimationChose(auto& entities) : SystemBase{ entities } {}
        void operator()(float) {
            each_entity([&](int id, auto& components) {
                if constexpr (checkAllOf<TypePack<HumanAnimation, State>, decltype(components)>()) {
                    auto [animation, state] = getCmpts<HumanAnimation, State>(components);
                    if (!state.isOnGround) {
                        animation.stop();
                        animation.play("jump");
                    }
                    else {
                        animation.play("walk");
                    }
                }
                });
        }
    };
    struct ShootS : private SystemBase {
        ShootS(auto& entities) : SystemBase{ entities } {}
        void operator()(float dt) {
            each_entity([&](int id, auto& components) {
                if constexpr (checkAllOf<TypePack<Shoot, Direction, Transform, Collision >, decltype(components)>()) {
                    auto [shoot, direction, transform, collision] = getCmpts<Shoot, Direction, Transform, Collision>(components);
                    if (shoot.isShootNow) {
                        shoot.currentTime += dt;
                        shoot.sendShoot = false;
                    }
                    if (shoot.isShootNow && shoot.currentTime >= shoot.cooldown) {
                        shoot.currentTime = 0;
                        shoot.isShootNow = false;
                    }
                    if (shoot.sendShoot && shoot.currentTime < shoot.cooldown && !shoot.isShootNow) {
                        shoot.isShootNow = true;
                        get_entity([&](auto& sndCmpts) {
                            if constexpr (checkAllOf<Direction, decltype(sndCmpts)>()) {
                                auto [snd_dir, snd_collision, snd_transform] = getCmpts<Direction, Collision, Transform>(sndCmpts);
                                snd_dir.x = direction.currentDir;
                                if (direction.currentDir > 0) {
                                    snd_transform.position.x += collision.box.w;
                                }
                                else if (direction.currentDir < 0) {
                                    snd_transform.position.x -= snd_collision.box.w;
                                }
                            }
                            }, create_entity<Bullet>({ transform.position.x, transform.position.y + 20.f }));
                        
                    }
                    

                }

            });
        }
    };



}

template<typename ... Ts> struct tuple_system {
  tuple_system(auto & arg): tuple{Ts{arg}...} {}
  std::tuple<Ts...> tuple;
};

struct Systems: tuple_system<System::CollisionS, System::Static, System::IsOnGround, System::Move,  System::InputS, System::DashS,  System::AnimationChose, System::AnimationS, System::Fall, System::AttackS, System::HealthCheck, System::Death, System::ShootS, System::EnemyLogicS, System::Draw, System::UI> {
 Systems(auto & entities): tuple_system{entities} {};
  void update(float dt) {
    std::apply([&](auto & ... sys) {
      (sys(dt), ...);
    }, tuple);
  }
};
