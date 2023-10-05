#pragma once
#include <vector>
#include <map>
#include <memory>
#include <typeinfo>
#include <SFML/Graphics.hpp>

class Entity;

using EntityVector = std::vector<std::unique_ptr<Entity>>;
using EntitiesAliasVector = std::vector<Entity*>;



class EnittyManager
{
	EntityVector AllEntities;
	std::map<size_t, EntitiesAliasVector> GroupedEntities;
public:
	template<typename T, typename... Args>
	T& Create(Args... args) {
		static_assert(std::is_base_of<Entity, T>::value, "T is not a member of Entity");

		//Create a uniqe ptr for the entity
		auto ptr{ std::make_unique<T>(std::forward<Args>(args)...) };

		//Alias ptr for the created entity to be stored in the vector
		auto AliasPtr = ptr.get();

		auto hash = typeid(T).hash_code();

		GroupedEntities[hash].emplace_back(AliasPtr);

		AllEntities.emplace_back(std::move(ptr));

		return *AliasPtr;
	}

	void Refresh();
	void Clear();

	template<typename T>
	auto& GetAll() {
		return GroupedEntities[typeid(T).hash_code()];
	}
	
	template<typename T, typename Func>
	void ApplyAll(const Func& func) {
		auto& entityGroup = GetAll<T>();

		for (auto ent : entityGroup) {
			func(*dynamic_cast<T*>(ent));
		}
	}

	void Update();
	void Draw(sf::RenderWindow& Window);
};

