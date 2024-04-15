#include "EnittyManager.h"
#include <algorithm>
#include "Entity.h"

void EntityManager::Refresh()
{
	for (auto& [type, alias_vector] : GroupedEntities) {
		alias_vector.erase(remove_if(begin(alias_vector), end(alias_vector),
			[](const auto& p) { return p->IsDestroyed(); }
		),
			end(alias_vector));
	}
	AllEntities.erase(remove_if(AllEntities.begin(), AllEntities.end(), [](const auto& p) {return p->IsDestroyed(); }), AllEntities.end());
}

void EnittyManager::Clear()
{
	GroupedEntities.clear();
	AllEntities.clear();
}

void EnittyManager::Update()
{
	for (auto& e : AllEntities) {
		e->Update();
	}
}

void EnittyManager::Draw(sf::RenderWindow& Window)
{
	for (auto& e : AllEntities) {
		e->Draw(Window);
	}
}
