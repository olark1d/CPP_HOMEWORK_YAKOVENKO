#include <iostream>
#include <cmath>

class Vector2d 
{
private:
    float x, y;
    static int instanceCount;

public:
    Vector2d(float x = 0.0, float y = 0.0) : x(x), y(y) 
    {
        ++instanceCount;
    }

    Vector2d(const Vector2d& other) : x(other.x), y(other.y) 
    {
        ++instanceCount;
    }

    ~Vector2d() 
    {
        --instanceCount;
    }

    Vector2d& operator=(const Vector2d& other) 
    {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Vector2d operator+(const Vector2d& secondVector) const 
    {
        return Vector2d(x + secondVector.x, y + secondVector.y);
    }

    Vector2d operator-(const Vector2d& secondVector) const 
    {
        return Vector2d(x - secondVector.x, y - secondVector.y);
    }

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) 
    {
        return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
    }

    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) 
    {
        return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
    }

    void operator*=(float scalar) 
    {
        x *= scalar;
        y *= scalar;
    }

    float operator()() const 
    {
        return std::sqrt(x * x + y * y);
    }

    float& operator[](std::size_t idx) 
    {
        if (idx == 0) return x;
        else if (idx == 1) return y;
        throw std::out_of_range("Index out of range");
    }

    const float& operator[](std::size_t idx) const 
    {
        if (idx == 0) return x;
        else if (idx == 1) return y;
        throw std::out_of_range("Index out of range");
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec) 
    {
        os << "{" << vec.x << "; " << vec.y << "}";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector2d& vec) 
    {
        is >> vec.x >> vec.y;
        return is;
    }

    static int getInstanceCount() 
    {
        return instanceCount;
    }
};

int Vector2d::instanceCount = 0;

int main() 
{
    Vector2d vec1{1.2, 5.6};
    Vector2d vec2{3.4, 7.8};
    Vector2d vec3 = vec1 + vec2;

    std::cout<<"vec1: "<<vec1<<std::endl;
    std::cout<<"vec2: "<<vec2<<std::endl;
    std::cout<<"vec3 (vec1 + vec2): "<<vec3<<std::endl;

    vec3 *= 2.0;
    std::cout<<"vec3 after scaling by 2: "<<vec3<<std::endl;

    std::cout<<"Length of vec3: "<<vec3()<<std::endl;

    std::cout<<"vec3[0]: "<<vec3[0]<<", vec3[1]: "<<vec3[1]<<std::endl;

    std::cout<<"Active instances: "<<Vector2d::getInstanceCount()<<std::endl;

    Vector2d inputVec;
    std::cout<<"Enter a vector (x y): ";
    std::cin>>inputVec;
    std::cout<<"You entered: "<<inputVec<<std::endl;

    std::cout<<"Active instances after input: "<<Vector2d::getInstanceCount()<<std::endl;
}