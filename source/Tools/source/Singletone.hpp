
template <typename T>
class Singleton
{
public:
    static T& instance()
    {
        static T _instance;
        return _instance;
    }
protected:
    Singleton() { }
    ~Singleton() { }
public:
    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const &) = delete;
};
