#include"classes.h"

//		Human	
void Human::set_last_name(const std::string& last_name)
{
	std::regex rgx_last_name_ru("[А-Я][а-я]{1,20}");
	std::regex rgx_last_name_en("[A-Z][a-z]{1,20}");
	this->last_name = ((std::regex_match(last_name, rgx_last_name_ru, std::regex_constants::match_default)) || (std::regex_match(last_name, rgx_last_name_en, std::regex_constants::match_default)) ? last_name : "Неизвестный формат");
}
void Human::set_first_name(const std::string& first_name)
{
	std::regex rgx_first_name_ru("[А-Я][а-я]{1,20}");
	std::regex rgx_first_name_en("[A-Z][a-z]{1,20}");
	this->first_name = ((std::regex_match(first_name, rgx_first_name_ru, std::regex_constants::match_default)) || (std::regex_match(last_name, rgx_first_name_en, std::regex_constants::match_default)) ? first_name : "Неизвестный формат");
}
const std::string& Human::get_last_name()const
{
	return last_name;
}
const std::string& Human::get_first_name()const
{
	return first_name;
}
unsigned int Human::get_age()const
{
	return age;
}
void Human::set_age(unsigned int age)
{
	this->age = age;
}
Human::Human(const std::string& last_name, const std::string& first_name, unsigned int age)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	std::cout << "HConstructor:\t" << this << std::endl;
}
Human::~Human()
{
	std::cout << "HDestructor:\t" << this << std::endl;
}

void Human::print()
{
	/*std::cout <<"\n"<< last_name << "\t" << first_name << "\t" << age <<( age >= 11 && age <= 14 ? " лет" : age % 10 == 1 ? " год" : age%10==2||age%10==4 ? " года" : " лет")<< std::endl;*/
	std::cout.width(8);
	std::cout << last_name << "\t";
	std::cout.width(8);
	std::cout << first_name << "\t";
	std::cout.width(8);
	std::cout << age << std::endl;
}


//		Student
const std::string& Student::get_specialty()const
{
	return spec;
}
const std::string& Student::get_group()const
{
	return group;
}
unsigned int Student::get_rating()const
{
	return rating;
}
unsigned int Student::get_attendence()const
{
	return attendence;
}
void Student::set_specialty(const std::string& spec)
{
	this->spec = spec;
}
void Student::set_group(const std::string& group)
{
	std::regex rgx_group_ru("(СТ|ПС|ВШ)(_| )(ПУ|ПВ|ИТУ|ИТВ|ДУ|ДВ)(_| )(\\d{2}|\\d{2})");
	std::regex rgx_group_en("(ST|PS|VS)(_| )(PU|PV|ITU|ITV|DU|DV)(_| )\\d{2}");
	this->group = ((std::regex_match(group, rgx_group_ru, std::regex_constants::match_default)) || (std::regex_match(group, rgx_group_en, std::regex_constants::match_default)) ? group : throw std::exception("Error: Bad group."));
}
void Student::set_rating(unsigned int rating)
{
	this->rating = rating <= 100 ? rating : 100;
}
void Student::set_attendence(unsigned int attendence)
{
	this->attendence = attendence <= 100 ? attendence : 100;
}
Student::Student
(
	const std::string& last_name, const std::string& first_name, unsigned int age,
	const std::string& spec, const std::string& group, unsigned int rating , unsigned int attendence
) :Human(last_name, first_name, age)
{
	set_specialty(spec);
	set_group(group);
	this->rating = rating;
	this->attendence = attendence;
	std::cout << "SConstructor:\t" << this << std::endl;
}
Student::~Student()
{
	std::cout << "SDestructor:\t" << this << std::endl;
}
void Student::print()
{
	Human::print();
	std::cout.width(8);
	std::cout << spec << "\t";
	std::cout.width(8);
	std::cout << group << "\t";
	std::cout.width(8);
	std::cout << "успеваемость " << rating << "%\t";
	std::cout.width(8);
	std::cout << "посещаемость " << attendence << "%" << std::endl;
}

//		Graduate
void Graduate::set_tesis(const std::string& tesis)
{
	this->tesis = tesis;
}
void Graduate::set_curator(const std::string& curator)
{
	this->curator = curator;
}
const std::string& Graduate::get_tesis()const
{
	return tesis;
}
const std::string& Graduate::get_curator()const
{
	return curator;
}
const unsigned int Graduate::get_plagiatory()const
{
	return plagiatory;
}
void Graduate::set_plagiatory(unsigned int plagiatory)
{
	this->plagiatory = plagiatory <= 100 ? plagiatory : 100;
}
Graduate::Graduate(
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
Graduate::~Graduate()
{
	std::cout << "GDestructor:\t" << this << std::endl;
}
void Graduate::print()
{
	Student::print();
	std::cout << "Тема диплома: " << tesis << ",\tимя куратора: " << curator << ",\tпроцет плагиата: " << plagiatory << "%\n" << std::endl;
}

//		Teacher
const std::string& Teacher::get_subject()const
{
	return subject;
}
const unsigned int Teacher::get_number_of_groups()const
{
	return experience;
}
const unsigned int Teacher::get_evil()const
{
	return evil;
}
void Teacher::set_subject(const std::string& subject)
{
	this->subject = subject;
}
void Teacher::set_experience(unsigned int number_of_groups)
{
	this->experience = number_of_groups;
}
void Teacher::set_evil(unsigned int evil)
{
	this->evil = evil <= 100 ? evil : 100;
}

//		Constructors:
Teacher::Teacher(
	const std::string& last_name, const std::string& first_name, unsigned int age,
	const std::string& subject, unsigned int number_of_groups, unsigned int evil
) : Human(last_name, first_name, age)
{
	set_subject(subject);
	set_experience(number_of_groups);
	this->evil = 20;
	std::cout << "TCounstructor:\t" << this << std::endl;
}
Teacher::~Teacher()
{
	std::cout << "TDestructor:\t" << this << std::endl;
}

void Teacher::print()
{
	Human::print();
	std::cout.width(8);
	std::cout << subject << "\t";
	std::cout << "опыт преподавания: " << experience << ", уровень злости: " << "\t" << evil << "%" << std::endl;
}