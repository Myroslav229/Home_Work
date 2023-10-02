#pragma once
#include "Math.h"
#include <set>
#include <tuple>


template<typename ... Ts> struct TypePack {};

template<typename T, typename ... Ts> constexpr bool areAnySame = (... || std::is_same_v<T, Ts>);

template<typename T, typename ... Ts> constexpr bool areBaseSame = (... || std::is_base_of_v<T, Ts>);

template <typename, typename> struct checkAllOfBase {};

template <typename T, typename ... Ts> struct checkAllOfBase<T, std::tuple<Ts...>&>
: std::bool_constant<(areBaseSame<T, Ts...>)>
{};

template <typename, typename> struct checkAllOf {};

template <typename T, typename ... Ts> struct checkAllOf<T, std::tuple<Ts...> &>
  : std::bool_constant<(areAnySame<T, Ts...>)>
{};

template <typename ... Ts, typename ... Us> struct checkAllOf<TypePack<Ts...>, std::tuple<Us...> &>
  : std::bool_constant<(areAnySame<Ts, Us...> && ...)>
{};

template<typename... Ts> decltype(auto) getCmpts(auto & tuple) {
  return std::tuple<Ts & ...>{std::get<Ts>(tuple)...};
}

template<typename T, typename... Ts> void getCmptsFromBase(auto && f, std::tuple<Ts...>& tuple) {
	([&] {
		if constexpr (std::is_base_of_v<T, Ts>) { f(std::get<Ts>(tuple)); }
	}(), ...);
}
// components of entity (player, enemy, etc..)

struct Health { 
	Health() {
		point = defaultHealth;
	}
	float defaultHealth = 100;
	float point{};
};

struct Attack { float damage = 10; };

struct Transform {
	Vector2D position;
	Vector2D tempPosition;
	float angle{};
	bool isStanding() {
		return position.y == tempPosition.y;
	}
};

struct Sprite {
	Sprite(std::string name, Vector2D position = {}) : sheet{ texture_pack[name] } {
		element.setTexture(sheet.get().texture);
		element.setTextureRect(sheet.get().frame.begin()->second);
		element.setPosition(position.x, position.y);
	}
	std::reference_wrapper <SpriteSheet> sheet = texture_pack["player"];
	sf::IntRect toDir(sf::IntRect int_rect, float dir) {
		if (dir < 0) {
			int_rect.left += int_rect.width;
			int_rect.width = -int_rect.width;
		}

		return int_rect;
	};
	void setFrame(std::string name, float dir = 0){
		element.setTextureRect(toDir(sheet.get().frame[name], dir));
	}
	sf::Sprite element;
};

struct Animation {
	Animation(){}
	void play(std::string name) { currentName = name; isEnabled = true; }
	void stop() { isEnabled = false; currentFrame = 0; currentName = {}; currentTime = 0; }
	std::map <std::string, std::tuple <int, float, bool>> pack;
	void addAnimation(std::string name, int frames, float frameTime, bool isLoop){
		pack[name] = { frames, frameTime, isLoop };
	}
	std::string currentName;
	int currentFrame=0;
	float currentTime=0;
	bool isEnabled = 0;
	float dir{};
};

struct HumanAnimation: public Animation {
	HumanAnimation() {
		addAnimation("walk", 4, 0.3f, true);
		addAnimation("jump", 0, 1.f, false);
	}
};

struct Direction : public Vector2D {
	float currentDir = 1;
};

struct Velocity : public Vector2D {
	Velocity(Vector2D val) : Vector2D{ val }, start{ val }{}
	Vector2D start{};
	bool needToNormalize{};
};

struct Dash: public Vector2D{
	Dash(Vector2D val) : Vector2D{ val }{}
	bool needGround{};
	bool sendDash{};
	bool isOnDash{};
	float cooldown = 0.1f;
	float currentTime{};
};
struct Jump : public Dash {
	Jump() : Dash{ {0 , -653.33f * 240 / 60} } {
		cooldown = 0.1f; needGround = true;
	}
};
struct DamageDiscarding : public Dash {
	DamageDiscarding() : Dash{ {-653.33f * 60 / 60 , -653.33f * 60 / 60} } {}
};

struct Shoot{

	bool sendShoot{};
	bool isShootNow{};
	float cooldown = 0.5f;
	float currentTime{};
};

struct State {

	bool collideWithSame{};
	bool isOnGround{};
	bool isOn—eiling{};
};

struct Input {};

enum class CollisionGroup {
	Static,
	Default,
	PickUp,
	Bullet,
	Sensor,
};

struct Box { float w{}; float h{}; };

struct Collision {
	CollisionGroup group{};
	std::set<CollisionGroup> collWith{};
	Box box{};
	std::set<int> callback;
};

struct Camera {};

struct EnemyLogic {
	bool seePlayer{};
};
struct Mass {};
