#include"classes.h"

#define POLYMORPHISM
//#define REGEX
//#define SYNTAX_GROUP
//#define REGEX_EMAIL
//#define REGEX_PHONE
//#define CONVERT_PHONE

void main()
{
	setlocale(LC_ALL, "");
	/*setlocale(LC_ALL, "");
	Human human("�������", "������", 18);
	Student stud("�������", "������", 18, "������", "�� �� 37");
	stud.print();
	Teacher ("�������", "�����", 65, "������", 5, 1000000).print();
	Graduate ("�������", "������", 11, "������", "�� �� 37",34,0, "������ ��������","������", 0).print();*/

#ifdef POLYMORPHISM
	Human* Group[] =
	{
		new Teacher("������", "����", 35, "C++", 5, 32),
		new Student("���������", "�����", 15, "���", "�� �� 35",95,100),
		new Student("�������", "�����", 15, "���", "�� �� 35",85,97),
		new Student("��������", "������", 16, "���", "�� �� 35",99,100),
		new Graduate("��������", "������", 16, "���", "�� �� 35",99,100,"�������� ��������� �����","��",0)
	};
	for (int i = 0; i < sizeof(Group) / sizeof(Human*); i++)
	{
		std::cout << "------------------------------------------------------------------------------------------\n";
		Group[i]->print();
	}
	for (int i = 0; i < sizeof(Group) / sizeof(Human*); i++)
	{
		delete Group[i];
	}
#endif // POLYMORPHISM

#ifdef REGEX
	std::string name;
	std::cout << "Input name: "; std::cin >> name;
	std::regex rgx("[A-Z][a-z]{1,20}");
	std::cout << std::regex_match(name, rgx, std::regex_constants::match_default) << std::endl;
#endif // REGEX

#ifdef SYNTAX_GROUP
	std::regex rgx_group_ru("(��|��(_| )(SB|VS)|��)(_| )(��|��|���|���|��|��)(_| )\\d{2}[���]?");
	std::regex rgx_group_en("(ST|PS(_| )(SB|VS))(_| )(PU|PV|ITU|ITV|DU|DV)(_| )\\d{2}[abv]?");
	std::string group("ST PV 35v");
	std::cout << "Input group: "; getline(std::cin, group);
	std::regex rgx_replace(" |\-");
	group = std::regex_replace(group, rgx_replace, "_", std::regex_constants::match_default);
	std::cout << std::regex_match(group.c_str(), rgx_group_en, std::regex_constants::match_default) << std::endl;
	std::cout << group << std::endl;
#endif // SYNTAX_GROUP

#ifdef REGEX_EMAIL
	std::regex rgx_email("\\w{3,50}@[a-z]{1,20}.[a-z]{2,3}");
	std::string email;
	std::cout << "Input email: ";
	std::cin >> email;
	std::cout << std::regex_match(email, rgx_email, std::regex_constants::match_default) << std::endl;
#endif // REGEX_EMAIL

#ifdef REGEX_PHONE
	std::string phone = "+38(099)943-04-24";
	/*std::regex rgx_phone("\\+\\d{2}\\(\\d{3}\\)\\d{3}(-\\d{2}){2}");*/
	std::regex rgx_phone(R"(\+\d{2}\(\d{3}\)\d{3}(-\d{2}){2})");
	std::cout << std::regex_match(phone, rgx_phone, std::regex_constants::match_default) << std::endl;
#endif // REGEX_PHONE

#ifdef CONVERT_PHONE
	std::string phone = "380999430424";
	std::regex rgx("\\d{12}");
	if (std::regex_match(phone, rgx, std::regex_constants::match_default))
	{
		phone.insert(0, "+");
		phone.insert(phone.size() - 10, "(");
		phone.insert(phone.size() - 7, ")");
		phone.insert(phone.size() - 2, "-");
		phone.insert(phone.size() - 5, "-");
	}
	std::cout << phone << std::endl;
#endif // CONVERT_PHONE


}
