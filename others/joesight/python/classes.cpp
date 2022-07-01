#include <iostream>

class Hello
{
    public:
        explicit Hello(void)
        {
            // this->n = n;
            std::cout << "This object has been initialized.\n";
        }

        void say_hello(void)
        {
            std::cout << "Hello, world." << std::endl;
        }

        void say_bye(void)
        {
            std::cout << "Bye, world.\n";
        }

        // int n;
};

int main()
{
    Hello eiei;

    eiei.say_hello();

    return 0;
}
