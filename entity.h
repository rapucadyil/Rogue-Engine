#include "definitions.h"
#pragma once
class Entity {
public:
	u32 entity_id;
	const str entity_name;
	bool active;

	Entity();
	Entity(u32 id, const str name, bool active);
	~Entity();

	void update();
	void render();
private:
	void tick();

};

typedef enum ItemType {
	It_Potion,
	It_Weapon,
	It_Spell,
};

class Item : public Entity {
public:
	ItemType type;
	Item(u32 id, const str name, bool active, ItemType type)
	: Entity(id, name, active){
		this->type = type;
	}
};