
class String
{
	public:
		String(const char *str=NULL);//普通构造函数
		String(const String &other)；//拷贝构造函数
		~String();                   //析构函数
		String& operator=(const String &other);//赋值函数

	private:
		char *m_data;
};

//普通构造函数
String::String(const char*str=NULL)
{
	if(NULL==str)
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		int length = strlen(str);
		m_data = new char[length+1];
		strcpy(m_data,str);
	}
}

//destructor function
String::~String()
{
	delete [] m_data;
}

//copy constructor function
String::String(const String &other)
{
	int length = strlen(other.m_data);
	m_data = new char[1+length];
	strcpy(m_data,other.m_data);
}

//operator= function
String& String::operator=(const String& other)
{
	if(this==&other)
	  return *this; //检测自赋值

	delete [] m_data;

	int length = strlen(other.m_data);
	m_data = new char[1+length];
	strcpy(m_data,other.m_data);

	return *this;
}
