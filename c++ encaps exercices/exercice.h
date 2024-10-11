#ifndef POINT_H
#define POINT_H

class Vector2 {
private:
    std::vector<float> _vector2;
public:
    // Setter
    void setVector2(float x, float y);
    
    // Getter
    std::vector<float> getVector2();
};

class Entity {
private:
    Vector2 v;
public:
    Entity(float x, float y);
    void Entitypos(float x, float y);
    std::vector<float> getEntitypos();
    virtual ~Entity() {} 
};

class AMovable {
protected:   
    float _vit = 1.0f;
    float speed;
    std::vector<float> direction;
    Vector2 v;

public:
    AMovable(float _x, float _y);
    virtual void SetterDirection(float dirX, float dirY);
    virtual void SetterSpeed(float _v);
    virtual float getSpeed() const;
    virtual void SetterMove() = 0;
};

class Alive {
private:
    float _maxlife;
    float _life;

public:
    Alive(float _maxlife);
    virtual float GetterMaxLife();
    virtual float GetterLife();
    virtual void TakeDamage(float damage);
};

class IAttacker {
public:
    virtual void attack(Alive& target) = 0;
};

class StaticObject : public Entity {
public:
    StaticObject(int posX, int posY);
};

class BreakableObject : public Entity, public Alive {
public:
    BreakableObject(float maxLife, int posX, int posY);
    void TakeDamage(float damage) override;
};

class Mob : public Entity, public Alive, public AMovable {
public:
    Mob(int posX, int posY, int maxLife, int dirX, int dirY);
    void TakeDamage(float damage) override;
    void SetterMove() override;
};

class Player : public Entity, public IAttacker, public Alive, public AMovable {
    public:
    Player(int posX, int posY, int maxLife, int dirX, int dirY);
    void TakeDamage(float damage) override;
    void SetterMove() override;
    void attack(Alive& target) override;
};

class World {
private:
    std::vector<Entity*> entities;

public:
    bool hasAliveEntities() const;
    void Init();

    void Step();

    ~World();
};

#endif