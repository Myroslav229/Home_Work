#pragma once
#include "Components.h"
template<typename ... Ts> struct EntityBase {
  EntityBase(auto && ... args): components{(decltype(args))args...} {}
	std::tuple<Ts...> components;
};


class Player: public EntityBase<State, Transform, Direction, Health, Input, Shoot, Sprite, Velocity, Collision, Jump , DamageDiscarding, Camera, Mass, HumanAnimation> {
public:
    Player(Vector2D position = {}) : EntityBase{
    State{.collideWithSame= true},
    Transform{position},
    Direction{},
    Health{},
    Input{},
    Shoot{},
    Sprite{"player", position},
    Velocity{{250.f, 250.f}},
    Collision{.group = CollisionGroup::Default,
    .collWith{CollisionGroup::Default, CollisionGroup::Static, CollisionGroup::Bullet, CollisionGroup::PickUp, CollisionGroup::Sensor},
    .box{64, 128} },
    Jump{},
    DamageDiscarding{},
    Camera{},
    Mass{},
    HumanAnimation{}
    } {}
};
class Enemy: public EntityBase<State, Transform, Direction, Health, Sprite, Velocity, Collision, Jump, DamageDiscarding, Mass, HumanAnimation, Shoot, Attack, EnemyLogic> {
public:
    Enemy(Vector2D position = {}) : EntityBase{
    State{.collideWithSame = false},
    Transform{position},
    Direction{},
    Health{},
    Sprite{"enemy", position},
    Velocity{{250.f, 250.f}},
    Collision{.group = CollisionGroup::Default,
    .collWith{CollisionGroup::Static, CollisionGroup::Bullet},
    .box{64, 128}},
    Jump{},
    DamageDiscarding{},
    Mass{},
    HumanAnimation{},
    Shoot{},
    Attack{.damage = 5},
    EnemyLogic{}
    } {}
};

class Bullet : public EntityBase<Transform, Direction,  Sprite, Velocity, Collision, Attack> {
public:
    Bullet(Vector2D position = {}) : EntityBase{
    Transform{position},
    Direction{},
    Sprite{"bullet0", position},
    Velocity{{400.f, 250.f}},
    Collision{.group = CollisionGroup::Bullet,
    .collWith{CollisionGroup::Default, CollisionGroup::Static, CollisionGroup::Bullet},
    .box{32, 24}},
    Attack{.damage = 20},
    } {}
}; 

struct MedicalKit : EntityBase<State, Transform, Direction, Health, Sprite, Velocity, Collision, Mass, Attack> {
    MedicalKit(Vector2D position = {}) : EntityBase{
    State{},
    Transform{position},
    Direction{},
    Health{},
    Sprite{"medkit", position},
    Velocity {{0,0}},
    Collision{.group = CollisionGroup::PickUp,
    .collWith{CollisionGroup::Default, CollisionGroup::Static},
    .box{32, 32}},
    Mass{},
    Attack{.damage = -20},
    } {}

};

struct Tile: public EntityBase<State, Transform, Collision, Sprite> {
	Tile(Vector2D position = {}, std::string name = "block0"): EntityBase {
    State{},
    Transform{position},
    Collision{.group = CollisionGroup::Static,
    .collWith{CollisionGroup::Bullet},.box{.w = 64, .h = 64}},
    Sprite{name, position}
  } {}
};

struct Background : public EntityBase< Transform, Sprite> {
    Background(Vector2D position = {}, std::string name = "background") : EntityBase{
    Transform{position},
    Sprite{name, position},
    } {}
};
struct Win : public EntityBase<State, Transform, Collision, Sprite>{
    Win(Vector2D position = {}, std::string name = "win") : EntityBase {
    State{},
    Transform{position},
    Collision{.group = CollisionGroup::Sensor,
    .collWith{CollisionGroup::Default},.box{.w = 256, .h = 256}},
    Sprite{name, position}
  } {}
};

using Entity = std::variant<Player, Enemy, Tile, Bullet, MedicalKit, Background, Win>;
using Entities = std::map<int, Entity>;
