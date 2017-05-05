#include "Question.hpp"
#include <iostream>
#include <string>
using namespace std;

void QuestionBase:: Display()
{
	cout << m_questionText;
}

void QuestionBase::SetQuestionText(const string& text)
{
	m_questionText = text;
}

void TrueFalseQuestion::Display()
{
	QuestionBase::Display();
	cout << "Options: (T)rue/(F)alse";
}

void TrueFalseQuestion::SetCorrectAnswer(const string& correctAnswer)
{
	m_correctAnswer = correctAnswer;
}

bool TrueFalseQuestion::CheckAnswer(const string& userAnswer)
{
	if (userAnswer == m_correctAnswer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MultipleChoiceQuestion::Display()
{
	QuestionBase::Display();
	for (int i = 0; i < 4; i++)
	{
		cout << i << ". " << m_answers[i];
	}
}

void MultipleChoiceQuestion::SetCorrectAnswer(int correctAnswer)
{
	m_correctAnswer = correctAnswer;
}

bool MultipleChoiceQuestion::CheckAnswer(int userAnswer)
{
	if (userAnswer == m_correctAnswer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MultipleChoiceQuestion::SetAnswerChoices(const string& a0, const string& a1, const string& a2, const string& a3)
{
	m_answers[0] = a0;
	m_answers[1] = a1;
	m_answers[2] = a2;
	m_answers[3] = a3;
}