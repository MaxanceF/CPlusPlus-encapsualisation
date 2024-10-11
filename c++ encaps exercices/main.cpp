#include <vector>
#include <iostream>
#include <cmath>
#include "exercice.h"

void Vector2::setVector2(float x, float y) {
    _vector2 = {x, y};
}

std::vector<float> Vector2::getVector2() {
    return _vector2;
}

Entity::Entity(float x, float y) {
    v.setVector2(x, y);
}

void Entity::Entitypos(float x, float y) {
    v.setVector2(x, y);
}

std::vector<float> Entity::getEntitypos() {
    return v.getVector2();
}

AMovable::AMovable(float _x, float _y) {
    v.setVector2(_x, _y);
    SetterSpeed(_vit);
    SetterDirection(_x, _y);
}

void AMovable::SetterDirection(float dirX, float dirY) {
    direction = {dirX, dirY};
}

void AMovable::SetterSpeed(float _v) {
    speed = _v;
}

float AMovable::getSpeed() const {
    return speed;
}

Alive::Alive(float _maxlife) : _maxlife(_maxlife), _life(_maxlife) {}

float Alive::GetterMaxLife() {
    return _maxlife;
}

float Alive::GetterLife() {
    return _life;
}

void Alive::TakeDamage(float damage) {
    _life -= damage;
}

StaticObject::StaticObject(int posX, int posY) : Entity(posX, posY) {
    std::cout << "Static Object just created at x = " << posX << " and y = " << posY << std::endl;
}

BreakableObject::BreakableObject(float maxLife, int posX, int posY) : Alive(maxLife), Entity(posX, posY) {
    std::cout << "Breakable Object just created at x = " << posX << " and y = " << posY << " with " << maxLife << " life" << std::endl;
}

void BreakableObject::TakeDamage(float damage) {
    Alive::TakeDamage(damage);
    if (GetterLife() <= 0) {
        std::cout << "Breakable Object just broke" << std::endl;
    }
}

Mob::Mob(int posX, int posY, int maxLife, int dirX, int dirY)
    : Entity(posX, posY), Alive(maxLife), AMovable(dirX, dirY) {
    std::cout << "Mob just created at x = " << posX 
              << " and y = " << posY 
              << " with " << maxLife << " life "
              << "with direction x = " << dirX 
              << " and y = " << dirY << std::endl;
}

void Mob::TakeDamage(float damage) {
    Alive::TakeDamage(damage);
    if (GetterLife() <= 0) {
        std::cout << "Mob just died" << std::endl;
    }
}

void Mob::SetterMove() {
    std::vector<float> pos = getEntitypos();
    pos[0] += direction[0] * getSpeed();
    pos[1] += direction[1] * getSpeed();
    Entitypos(pos[0], pos[1]);
    std::cout << "Mob moved to x = " << pos[0] << " and y = " << pos[1] << std::endl;
}

Player::Player(int posX, int posY, int maxLife, int dirX, int dirY): Entity(posX, posY), Alive(maxLife), AMovable(dirX, dirY) {
    std::cout << "Player just created at x = " << posX 
              << " and y = " << posY 
              << " with " << maxLife << " life "
              << "with direction x = " << dirX 
              << " and y = " << dirY << std::endl;
}

void Player::TakeDamage(float damage) {
    Alive::TakeDamage(damage);
    if (GetterLife() <= 0) {
        std::cout << "Player just died" << std::endl;
    }
}

void Player::SetterMove() {
    std::vector<float> pos = getEntitypos();
    pos[0] += direction[0] * getSpeed();
    pos[1] += direction[1] * getSpeed();
    Entitypos(pos[0], pos[1]);
    std::cout << "Player moved to x = " << pos[0] << " and y = " << pos[1] << std::endl;
}

void Player::attack(Alive& target) {
    if(target.GetterLife() > 0){
    target.TakeDamage(10.0f);
    std::cout << "Player just attacked." << std::endl;
    }
    else{
        std::cout << "Target is already dead." << std::endl;
    }
}


void World::Init() {
    entities.push_back(new StaticObject(5, 10));
    entities.push_back(new BreakableObject(1.0f, 15, 20));
    entities.push_back(new Mob(30, 40, 20, 1, 1)); 
    entities.push_back(new Player(10, 20, 10, 1, 1)); 
}

/*void World::Step() {
    bool hasAliveMob = false;
    bool hasAliveBreakable = false;
    for (Entity* entity : entities) {
        if (Mob* mob = dynamic_cast<Mob*>(entity)) {
            hasAliveMob = true;
            for (Entity* target : entities) {
                if (BreakableObject* breakable = dynamic_cast<BreakableObject*>(target)) {
                    std::vector<float> mobPos = mob->getEntitypos();
                    std::vector<float> targetPos = breakable->getEntitypos();
                    if (std::abs(mobPos[0] - targetPos[0]) > 1 || std::abs(mobPos[1] - targetPos[1]) > 1) {
                        mob->SetterMove(); 
                    }
                    break; 
                }
            }
        }

        if (BreakableObject* breakable = dynamic_cast<BreakableObject*>(entity)) {
            hasAliveBreakable = true;
        }

        if (Player* player = dynamic_cast<Player*>(entity)) {
            if (hasAliveMob) {
                for (Entity* target : entities) {
                    if (Mob* mob = dynamic_cast<Mob*>(target)) {
                        std::vector<float> playerPos = player->getEntitypos();
                        std::vector<float> mobPos = mob->getEntitypos();
                        if (std::abs(playerPos[0] - mobPos[0]) <= 1 && std::abs(playerPos[1] - mobPos[1]) <= 1) {
                            player->attack(*mob); 
                        } else {
                            player->SetterMove(); 
                        }
                        break; 
                    }
                }
            } else {
                for (Entity* target : entities) {
                    if (BreakableObject* breakable = dynamic_cast<BreakableObject*>(target)) {
                        std::vector<float> playerPos = player->getEntitypos();
                        std::vector<float> breakablePos = breakable->getEntitypos();
                        if (std::abs(playerPos[0] - breakablePos[0]) <= 1 && std::abs(playerPos[1] - breakablePos[1]) <= 1) {
                            player->attack(*breakable); 
                        } else {
                            player->SetterMove(); 
                        }
                        break;
                    }
                }
            }
        }
    }


    if (!hasAliveMob && !hasAliveBreakable) {
        std::cout << "Simulation Finished" << std::endl;
    }
}

bool World::hasAliveEntities() const {
    bool hasAliveMob = false;
    bool hasAliveBreakable = false;

    for (Entity* entity : entities) {
        if (dynamic_cast<Mob*>(entity)) {
            hasAliveMob = true;
        }
        if (dynamic_cast<BreakableObject*>(entity)) {
            hasAliveBreakable = true;
        }
    }

    return hasAliveMob || hasAliveBreakable;
}


World::~World() {
    for (Entity* entity : entities) {
        delete entity; 
    }
}*/


int main() {
    Vector2 v;
    v.setVector2(5.5f, 15.9f);
    Entity e(100.5f, 200.7f);
    std::cout << "["<< v.getVector2()[0]<<", "
              << v.getVector2()[1] << "]"<< std::endl;
    std::cout << "["<<  e.getEntitypos()[0]<<", " 
              << e.getEntitypos()[1]<< "]" << std::endl;

    StaticObject staticObj(5, 10);

    BreakableObject breakableObj(50.0f, 15, 20);
    breakableObj.TakeDamage(20.0f);
    breakableObj.TakeDamage(40.0f); 

    Mob mob(30, 40, 100, 1, 1);
    mob.SetterMove();
    mob.TakeDamage(30.0f);
    mob.TakeDamage(80.0f); 

    Player player(10, 20, 100, 1, 1);
    player.SetterMove();
    player.TakeDamage(30.0f); 
    player.TakeDamage(80.0f); 

    BreakableObject breakableObjec(10.0f, 15, 20);
    player.attack(breakableObjec); 
    player.attack(breakableObjec);


    World world;
    world.Init();
    /*while (true) {
        world.Step();
    if (!world.hasAliveEntities()) {
            break;
        }
    }*/
    return 0;
}