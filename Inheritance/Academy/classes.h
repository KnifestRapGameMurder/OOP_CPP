#pragma once

#include<iostream>
#include<string>
#include<regex>

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
private:
	void set_last_name(const std::string& last_name);
	void set_first_name(const std::string& first_name);
public:
	const std::string& get_last_name()const;
	const std::string& get_first_name()const;
	unsigned int		get_age()const;
	void				set_age(unsigned int age);

	//		Constructors:

	Human(const std::string& last_name, const std::string& first_name, unsigned int age);
	virtual ~Human();

	virtual void print();
};





class Student :public Human
{
	std::string spec;
	std::string group;
	unsigned int rating;
	unsigned int attendence;
public:
	const std::string& get_specialty()const;
	const std::string& get_group()const;
	unsigned int get_rating()const;
	unsigned int get_attendence()const;

	void set_specialty(const std::string& spec);
	void set_group(const std::string& group);
	void set_rating(unsigned int rating);
	void set_attendence(unsigned int attendence);
	//		Constructors:
	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating = 0, unsigned int attendence = 0
	);

	~Student();

	void print();
};

class Graduate : public Student
{
	std::string tesis;
	std::string curator;
	unsigned int plagiatory;

private:
	void set_tesis(const std::string& tesis);
	void set_curator(const std::string& curator);
public:
	const std::string& get_tesis()const;
	const std::string& get_curator()const;
	const unsigned int get_plagiatory()const;
	void set_plagiatory(unsigned int plagiatory);

	//		Constructors:
	Graduate(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence,
		const std::string& tesis, const std::string& curator, unsigned int plagiatory
	);
	~Graduate();

	void print();
};

class Teacher : public Human
{
	std::string subject;
	unsigned int experience;
	unsigned int evil;
public:
	const std::string& get_subject()const;
	const unsigned int get_number_of_groups()const;
	const unsigned int get_evil()const;
	void set_subject(const std::string& subject);
	void set_experience(unsigned int number_of_groups);
	void set_evil(unsigned int evil);

	//		Constructors:
	Teacher(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& subject, unsigned int number_of_groups, unsigned int evil = 20
	);
	~Teacher();

	void print();
};