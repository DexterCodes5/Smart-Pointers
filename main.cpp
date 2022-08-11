#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make(); // auto make()
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);


std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
//    std::unique_ptr<std::vector<std::shared_ptr<Test>>> p = std::make_unique<std::vector<std::shared_ptr<Test>>>();
//    return p;
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    std::unique_ptr<int> num = std::make_unique<int>(0);
    std::cin >> *num;
    fill(*vec_ptr, *num);
    display(*vec_ptr);
    return 0;
}


void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    //int *count = new int(1);
    //int *count {nullptr};
    std::unique_ptr<int> count;
    std::unique_ptr<int> n = std::make_unique<int>(0);
    
    //std::shared_ptr<Test> t;
    std::unique_ptr<Test> t;
    for (int i = 1; i <= num; i++) {
        //*count = i;
        //count = new int(i);
        count = std::make_unique<int>(i);
        std::cout << "Enter data point[" << *count << "] : ";
        std::cin >> *n;
        //t = std::make_shared<Test>(*n);
        //t = std::make_unique<Test>(*n);
        //vec.push_back(std::move(t));
        vec.push_back(std::move(std::make_unique<Test>(*n)));
        //delete count;
    }
}
//std::shared_ptr<Test> ptr = std::make_shared<Test>(100);

void display(const std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "============== Displaying vector data ==================" << std::endl;
    for (const auto &t: vec)
        std::cout << t->get_data() << std::endl;
    std::cout << "========================================================" << std::endl;
}
