#ifndef POINT_H
#define POINT_H
#include <vector>

class Vector2
{
    private:
        std::vector<float> _vector2;
    public:
    //setter
    void setVector2(float x, float y){
        _vector2 = {x,y};
    }

    //getter
    std::vector<float> getVector2(){
        return _vector2;
    }

};

class Entity 
{
    private:
        Vector2 v;
    public:
        Entity(float x, float y)
        {
        v.setVector2(x, y);
        }
        void Entitypos(float x, float y){
            v.setVector2(x, y);
        }
        std::vector<float> getEntitypos(){
            return v.getVector2();
        }
};

class AMovable
{
    protected:   
        float _vit = 1.0f;
        float speed;
        std::vector<float> direction;
        Vector2 v;

    public:
        AMovable(float _x, float _y)
        {
        v.setVector2(_x, _y);
        SetterSpeed(_vit);
        SetterDirection(_x, _y);
        }

        virtual void SetterDirection(float dirX, float dirY) {
            direction = {dirX, dirY};
        }
        virtual void SetterSpeed(float _v){
            speed= _v;
        };
        virtual float getSpeed() const {
        return speed;
        }
        virtual void SetterMove() = 0;


};

class Alive{
    private:
        float _maxlife;
        float _life;

    public:
        Alive(float _maxlife){
            _life = _maxlife;
        }   
        virtual float GetterMaxLife(){
            return _maxlife;
        }
        virtual float GetterLife(){
            return _life;
        }
        virtual void TakeDamage(float damage){
            _life -= damage;
        }
};

class IAttacker {
    public:
        virtual void attack(Alive* target) = 0;
    };

class StaticObject : public Entity {

public:
    StaticObject(int posX, int posY) : Entity(posX, posY) {
        std::cout << "Static Object just created at x = " <<  posX << " and y = " << posY << std::endl;
    }
};

class BreakableObject: public Entity, public Alive {
public:
    BreakableObject(float maxLife, int posX, int posY) : Alive(maxLife), Entity(posX, posY) {
        std::cout << "Breakable Object just created at x = " << posX << " and y = " << posY << " with " << maxLife << std::endl;
    }

    void TakeDamage(float damage) override {
        Alive::TakeDamage(damage);
        if (GetterLife() <= 0) {
            std::cout << "Breakable Object just broke" << std::endl;
        }
    }
};


class Mob : public Entity, public Alive, public AMovable {
    private:
    int posX, posY, maxLife, dirX, dirY;
    public:
    Mob(int posX, int posY, int maxLife, int dirX, int dirY)
        : Entity(posX, posY), Alive(maxLife), AMovable(dirX, dirY) {
        std::cout << "Mob just created at x = " << posX 
                  << " and y = " << posY 
                  << " with " << maxLife << " life "
                  << "with direction x = " << dirX 
                  << " and y = " << dirY << std::endl;
    }

        void TakeDamage(float damage) override {
            Alive::TakeDamage(damage);
            if (GetterLife() <= 0) {
                std::cout << "Mob just died" << std::endl;
            }
        }

        void SetterMove() override {
            AMovable::SetterMove(); 
            std::vector<float> pos = getEntitypos();
            pos[0] += dirX * getSpeed();
            pos[1] += dirY * getSpeed();
            Entitypos(pos[0], pos[1]);
            std::cout << "Mob moved to x = " << pos[0] << " and y = " << pos[1] << std::endl;
        }
        
    
};

#endif