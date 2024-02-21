#include <iostream>
#include <string>
#include <vector>
//ПОТОМ РАЗОБРАТЬСЯ...НЕВЕРНЫЕ РЕШЕНИЯ


//делаем принт абстрактным и независимым для класса Printer (стр 166)
class IPrintable {
public:
	virtual std::string Info()const = 0;//если virtual = 0, то метод виртуальный и его реализации в классе нет
};


class Cat {
public:
	~Cat() {};
	std::string name;
	std::string breed_;
	std::string owner_;
	int age_;

	Cat() : name("no_name"), breed_("no_breed"), owner_("no_owner"), age_(0) {};

	Cat(std::string name, std::string breed, std::string owner, int age) {
		name = name;
		breed_ = breed;
		owner_ = owner;
		age_ = age;
	}
	void printCat()
	{
		std::cout << "Имя кота: " << name_ << '\n';
		std::cout << "Порода кота: " << breed_ << '\n';
		std::cout << "Хозяин кота: " << owner_ << '\n';
		std::cout << "Возраст кота: " << age_ << '\n';
	}
	std::string getName() {
		return name;
	}
};

class Hostel {
public:

	void addCat(const Cat& Cat)
	{
		counterCat++;
		if (counterCat > 5) throw - 1;
		obj_Cat.push_back(Cat);


	}

	void searchCat(const std::string& Cat)
	{
		for (auto i = obj_Cat.begin(); i != obj_Cat.end(); i++) {
			if (i->getName() == Cat)
			{
				std::cout << "Есть такой кот! " << Cat << '\n';
				return;
			}
		}
		std::cout << "Нет такого кота!\n";
		std::cout << std::endl;
	}
	void delCat(const std::string& Cat)
	{
		counterCat--;
		if (counterCat < 0) throw - 1;
		for (auto i = obj_Cat.begin(); i != obj_Cat.end(); i++) {
			if (i->getName() == Cat) {
				obj_Cat.erase(i);
				i = obj_Cat.begin();
			}
		}

	}

	void printAllCat() {
		std::cout << "Живут коты: \n";
		for (int i = 0; i < obj_Cat.size(); i++) {
			std::cout << obj_Cat[i].name << ',';
		}
		std::cout << std::endl;
	}

private:
	int maxQuantityCat_ = 5;
	int counterCat = 0;
	std::vector<Cat>obj_Cat;
};
//-------------------------------------------------------------------------

//дополнение к предыдущим трем занятиям
class Cat:public IPrintable {    //<-

public:
	std::string Info()const override {
		std::string result{};
		result += name;
		result += ' ';
		result += bride;
		result += ' ';
		result += owner;
		return result;
	}

	std::string name;
	std::string bride;
	std::string owner;
};

class Hotel {
public:
	Hotel(int capacity) {
		current_ = 0;
		capacity_ = capacity;
		cats_ = new Cat[capacity_]{};
	}

	//добавление кота
	void AddCat(const Cat& cat) {
		if (capacity_ > current_) {
			cats_[current_] = cat;
			current_ = +1;
		}
		else {
			throw - 1;
		}
	}

	//удаление кота
	Cat RemoveCat(int num) {
		if (num > current_ || num < 1) {
			throw - 1;
		}
		Cat result{ cats_[num - 1] };//сохраняем карточку и из картотеки удаляем все последующие шаги с этой карточкой
		std::swap(cats_[num - 1], cats_[current_ - 1]);
		//тут может быть очистка данных последнего хранимого элемента
		current_ -= 1;
		return result;
	}

	void NewCapacity(int i) {
		if (i < current_) {
			throw - 1;
		}
		Cat* tmp = new Cat[i]{};
		for (size_t j = 0; j < current_; j++){
			tmp[j] = cats_[j];
		}
		std::swap(tmp, cats_);
		capacity_ = i;
		delete[] tmp;
	}

	int Find(std::string name_cat_) {
		int result{ -1 };
		for (size_t i = 0; i < current_; i++)
		{
			if (cats_[i].name == name_cat_) {
				result = i + 1;
				break;
		}

		}
		return result;
	}

private:
	Cat* cats_;
	int capacity_;
	int current_;
};

//так делать не надо, так как всё будет завязано на одном классе
 class Printer {
public:
	static void Print(const Cat& obj){
	std::cout<<obj.Info()<<'\n';
};
	




int main() {
	system("chcp 1251>nul");
	int n, m;

	Cat fluffy;
	fluffy.name = "Миша";
	fluffy.name = "Рыжий";
	fluffy.name = "Алконафт";
	Printer::Print(fluffy);


	Cat cat1("Кирилл", "Русский", "Каролина", 32);
	Cat cat2("Саня", "Паша", "Леший", 5);
	Cat cat3("Серега", "Миша", "Рыжий", 6);
	Cat cat4("Мутный", "Ждан", "Илюха", 9);
	Cat cat5("Чили", "Темыч", "Ляпыч", 1);
	Cat cat6("Американец", "Перемотка", "Перевязка", 30);

	cat1.printCat();

	Hostel hostel1;
	hostel1.addCat(cat1);
	hostel1.addCat(cat2);
	hostel1.addCat(cat3);
	hostel1.addCat(cat4);
	hostel1.addCat(cat5);
	//hostel1.addCat(cat6);

	hostel1.printAllCat();
	hostel1.searchCat("Чили");
	hostel1.delCat("Кирилл");
	hostel1.printAllCat();






	return 0;
}