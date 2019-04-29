#include "definitions.h"
#include "entity_manager.h"
#include "entity.h"
int main(int argc, char** argv) {
	
	EntityManager *mgr = new EntityManager();
	create_prefab<Entity>(mgr, 'P');
	create_prefab<Item>(mgr, '!');
	system("PAUSE");
	return 0;
}
