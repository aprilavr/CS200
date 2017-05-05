#ifndef _QUESTION_HPP
#define _QUESTION_HPP
#include <string>
using namespace std;


class QuestionBase
{
public: void Display();
public: void SetQuestionText(const string& text);
protected: string m_questionText;
};

class TrueFalseQuestion: public QuestionBase
{
private: string m_correctAnswer;
public: void Display();
public: bool CheckAnswer(const string& userAnswer);
public: void SetCorrectAnswer(const string& correctAnswer);
};

class MultipleChoiceQuestion: public QuestionBase
{
private: int m_correctAnswer;
private: string m_answers[4];
public: void Display();
public: bool CheckAnswer(int userAnswer);
public: void SetCorrectAnswer(int correctAnswer);
public: void SetAnswerChoices(const string& a0, const string& a1, const string& a2, const string& a3);
};

#endif
