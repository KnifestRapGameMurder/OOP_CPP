#include<iostream>
#include<string>

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
private:
	void set_last_name(const std::string& last_name)
	{

		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//		Constructors:
	
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;
	}
	~Human()
	{
		std::cout << "HDestructor:\t" << this << std::endl;
	}

	void print()const
	{
		std::cout <<"\n"<< last_name << "\t" << first_name << "\t" << age <<( age >= 11 && age <= 14 ? " ���" : age % 10 == 1 ? " ���" : age%10==2||age%10==4 ? " ����" : " ���")<< std::endl;
	}
};

class Student:public Human
{
	std::string spec;
	std::string group;
	unsigned int rating;
	unsigned int attendence;
public:
	const std::string& get_specialty()const
	{
		return spec;
	}
	const std::string& get_group()const
	{
		return group;
	}
	unsigned int get_rating()const
	{
		return rating;
	}
	unsigned int get_attendence()const
	{
		return attendence;
	}

	void set_specialty(const std::string& spec)
	{
		this->spec = spec;
	}
	void set_group(const std::string& group)
	{
		this->group= group;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating<=100 ? rating : 100;
	}
	void set_attendence(unsigned int attendence)
	{
		this->attendence = attendence <= 100 ? attendence : 100;
	}
	//		Constructors:
	Student(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating = 0, unsigned int attendence = 0
	) :Human(last_name, first_name, age)
	{
		set_specialty(spec);
		set_group(group);
		this->rating = rating;
		this->attendence = attendence;
		std::cout << "SConstructor:\t" <<this<< std::endl;
	}
	~Student()
	{
		std::cout << "SDestructor:\t" << this << std::endl;
	}

	void print()const
	{
		Human::print();
		std::cout << spec << "\t" << group << ", ������������ " << rating << "%, ������������ " << attendence << "%" << std::endl;
	}
};

class Graduate : public Student
{
	std::string tesis;
	std::string curator;
	unsigned int plagiatory;

private:
	void set_tesis(const std::string& tesis)
	{
		this->tesis = tesis;
	}
	void set_curator(const std::string& curator)
	{
		this->curator = curator;
	}
public:
	const std::string& get_tesis()const
	{
		return tesis;
	}
	const std::string& get_curator()const
	{
		return curator;
	}
	const unsigned int get_plagiatory()const
	{
		return plagiatory;
	}
	void set_plagiatory(unsigned int plagiatory)
	{
		this->plagiatory = plagiatory <= 100 ? plagiatory : 100;
	}

	//		Constructors:
	Graduate(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence,
		const std::string& tesis, const std::string& curator, unsigned int plagiatory
	) : Student(last_name, first_name, age, spec, group, rating, attendence)
	{
		set_tesis(tesis);
		set_curator(curator);
		set_plagiatory(plagiatory);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}

	void print()
	{
		Student::print();
		std::cout <<"���� �������: "<< tesis << ",\t��� ��������: "<< curator << ",\t������ ��������: " << plagiatory << "%\n" << std::endl;
	}
};

class Teacher : public Human
{
	std::string subject;
	unsigned int experience;
	unsigned int evil;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	const unsigned int get_number_of_groups()const
	{
		return experience;
	}
	const unsigned int get_evil()const
	{
		return evil;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	void set_experience(unsigned int number_of_groups)
	{
		this->experience = number_of_groups;
	}
	void set_evil(unsigned int evil)
	{
		this->evil = evil<=100 ? evil : 100;
	}

	//		Constructors:
	Teacher(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& subject, unsigned int number_of_groups, unsigned int evil = 20
	) : Human(last_name, first_name, age)
	{
		set_subject(subject);
		set_experience(number_of_groups);
		this->evil = 20;
		std::cout << "TCounstructor:\t" << this << std::endl;
	}
	~Teacher()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}

	void print()
	{
		Human::print();
		std::cout << subject << "\t" <<", ���� ������������: " << experience<<", ������� ������: " << "\t" << evil <<"%" << std::endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("�������", "������", 18);
	human.print();
	Student stud("�������", "������", 18, "������", "�� �� 37");
	stud.print();
	Teacher ("�������", "�����", 65, "������", 5, 1000000).print();
	Graduate ("�������", "������", 11, "������", "�� �� 37",34,0, "������ ��������","������", 0).print();
}