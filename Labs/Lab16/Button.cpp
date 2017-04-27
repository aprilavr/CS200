#include "Button.hpp"

void Button::SetText(string text)
{
    m_text=text;
}

void Button::Draw() const
{
    int len = m_text.size() + 4;

	for ( int i = 0; i < len; i++ )
	{
		cout << "*";
	}
	cout << endl;
	cout << "* " << m_text << " *" << endl;

	for ( int i = 0; i < len; i++ )
	{
		cout << "*";
	}
	cout << endl;
}
