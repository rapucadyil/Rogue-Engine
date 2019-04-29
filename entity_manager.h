#pragma once
#include <vector>
#include <typeinfo>
#include "definitions.h"
#include "entity.h"
// TODO(rj): implement singleton pattern for this later...for now just make sure to instantiate only one
typedef enum class Prefab {
	Pf_Player,
	Pf_Enemy,
};

struct EntityManager {
	vector<Entity*> m_entities;
	EntityManager() {
		m_entities = vector<Entity*>();
	}
	~EntityManager() {
		for (auto* elem : m_entities) {
			delete elem;
		}
	}

	void update() {
		for (auto* elem : m_entities) {
			elem->update();
		}
	}

	void render_entities() {
		for (auto* elem : m_entities) { 
			elem->render();
		}
	}

};
template <typename T>
inline static void create_prefab(EntityManager *mgr, char req) {
	if (typeid(T) == typeid(Entity)) {
		cout << "Creating a " << typeid(T).name() << " entity" << endl;
		switch (req) {
		case 'P':
			Entity* player = new Entity(0, "Player", true);
			mgr->m_entities.push_back(player);
			break;
		}
	}
	else if (typeid(T) == typeid(Item)) {
		switch (req) {
		case '!':
			Item *heal = new Item(1, "Health Potion", true, ItemType::It_Potion);
			mgr->m_entities.push_back(heal);
			break;
		}
	}
}
