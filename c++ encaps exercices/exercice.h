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
        float _Ex =0.0f; 
        float _Ey =0.0f;
        Vector2 v;
    public:
        Entity()
        {
        v.setVector2(_Ex, _Ey);
        }
        void Entitypos(float _Ex, float _Ey){
            v.setVector2(_Ex, _Ey);
        }
        std::vector<float> getEntitypos(){
            return v.getVector2();
        }
};

class AMovable
{
    private:    
        float _x =1.0f; 
        float _y =1.0f;
        float _vit = 1.0f;
        float speed;
        std::vector<float> direction;
        Vector2 v;

    public:
        AMovable()
        {
        v.setVector2(_x, _y);
        SetterSpeed(_vit);
        SetterDirection(v.getVector2());
        }

        virtual void SetterDirection(std::vector<float> _dir){
            direction = {_dir};
        };
        virtual void SetterSpeed(float _v){
            speed= _v;
        };
        virtual void SetterMove() = 0;


};

#endif