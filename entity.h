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

	virtual void update();
	virtual void render();
protected:
	virtual void tick();

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

	void update() override;
	void render() override;

protected:
	void tick() override;
};