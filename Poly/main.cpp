

#include <iostream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

class Term
{
private:
    int coeff;
    int exp;

public:
    int getCoeff() const;
    int getExp() const;
    void setCoeff(const int coefficient);
    void setExp(const int exponent);

    double eval(const double x) const;
    Term derivative() const;
    Term multiply(const Term & term) const;

    void displayFirst() const;
    void displayNext() const;

};

class Poly
{
private:
    vector<Term> terms;		// Terms are in decreasing order of degree

public:
    // member functions
    Term getTerm(const int index) const;
    int degree() const;		// highest degree
    int termCount() const;	// number of terms

    void addTerm(const int coeff, const int exp);
    void scale(const int fact);

    double eval(const double x) const;		// evaluate polynomial with value x
    Poly derivative() const;				// derivative

    void display(const string & label) const;
    void displayMultiply(const Poly & poly, const string & label) const;

};

void display_banner();
Poly read_poly(const int label);
void display_stats(const Poly & poly, const string & label);
void evaluate_poly(const Poly & poly);
void goodbye_banner();

int main()
{
    Poly poly1, poly2;
    int scale;

    display_banner();

    poly1 = read_poly(1);
    cout << endl;
    display_stats(poly1, "You entered polynomial #1: ");

    poly2 = read_poly(2);
    cout << endl;
    display_stats(poly2, "You entered polynomial #2: ");

    cout << "Multiplication terms - " << endl << endl;;
    poly1.displayMultiply(poly2, "Poly #1 * Poly #2");

    poly2.displayMultiply(poly1, "Poly #2 * Poly #1");

    cout << endl;

    evaluate_poly(poly1);
    cout << endl;

    if (poly1.termCount() > 0) {
        cout << "Enter a scale factor to apply to polynomial #1: ";
        cin >> scale;
        poly1.scale(scale);
        display_stats(poly1, "The polynomial after scaling: ");
    }

    goodbye_banner();

return 0;
}

// CLASS TERM MEMBER FUNCTIONS
int Term::getCoeff() const //returns the coefficient of a term (an object of the term class)
{
    // Replace with your code
    return coeff;
}

int Term::getExp() const //returns the expoenent of the term
{
    // Replace with your code
    return exp;
}

void Term::setCoeff(const int coefficient) //updates the coefficient of the term
{
    // Replace with your code
    coeff = coefficient;
}

void Term::setExp(const int exponent) //updates the exponent of the term
{
    // Replace with your code
    exp = exponent;
}

double Term::eval(const double x) const //returns the evaluation of the term given an input value x passed the function

{
    // Replace with your code

    double evaluation = pow(x, exp) * coeff;

    return evaluation;

}

Term Term::derivative() const //returns the new term that is the derivative of the term the functions calls
{
    // Replace with your code

    Term derivative;

    if (getExp() == 0)
    {
        derivative.setCoeff(0);
        derivative.setExp(0);
    }
    else if (getExp() == 1)
    {
        derivative.setCoeff(coeff);
        derivative.setExp(0);
    }

    else
    {
        derivative.setCoeff(coeff * exp);
        derivative.setExp(exp - 1);
    }


    return derivative;

}

Term Term::multiply(const Term & term) const //returns a new term that is multiplication of the term the function is called on
{
    // Replace with your code
    Term mult;


    int c1;
    int c2;
    int c3, c4;
    //initialize coefficients
    c1 = getCoeff();
    c2 = term.getCoeff();


    //initialize exponents
    c3 = getExp();
    c4 = term.getExp();

    mult.setCoeff(c1*c2); //sets coefficient
    mult.setExp(c3 + c4); //sets exponent

    return mult; //sets the term



}

void Term::displayFirst() const //displays a term to the screen formatted as the first term in the polynomial
{
    // Replace with your code
    if (coeff < 0 && !(coeff == 1)) //if coefficient is negative put minus sign in front of it
    {

        if (exp == 1) //if exp is one then exponent is not displayed
        {
            cout << coeff << "x" << " ";
        }

        else if (exp == 0) //if exp is zero then only coefifcient is displayed
        {
            cout << coeff;
        }

        else
        {
            cout << coeff << "x^" << exp << " ";
        }



    }


    else if (coeff > 0 && !(coeff == 1)) //if coefficient is negative put minus sign in front of it
    {

        if (exp == 1) //if exp is one then exponent is not displayed
        {
            cout << coeff << "x";
        }

        else if (exp == 0) //if exp is zero then only coefifcient is displayed
        {
            cout << coeff;
        }

        else
        {
            cout << coeff << "x^" << exp;
        }


    }
    else if (coeff == 0 && exp == 0)
    {
        cout << "0";
    }
    else
    {

        if (exp == 1) //if exp is one then exponent is not displayed
        {
            cout << "x";
        }

        else if (exp == 0) //if exp is zero then only coefifcient is displayed
        {
            cout << "";
        }

        else
        {
            cout << "x^" << exp;
        }

    }


}
void Term::displayNext() const //displays a term to the second formatted as a term after the first in the polynomial
{
    // Replace with your code
    if (coeff < 0 && !(coeff == 1 || coeff == -1)) //if coefficient is negative put minus sign in front of it
    {
        cout << " - ";

        if (exp == 1) //if exp is one then exponent is not displayed
        {

            cout << abs(coeff) << "x";
        }

        else if(exp == 0) //if exp is zero then only coefifcient is displayed
        {
            cout << abs(coeff);
        }
        else if (exp == -1)
        {
            cout << "";
        }

        else
        {

            cout << abs(coeff) << "x^" << exp;
        }


    }

    else if (coeff > 0 && !(coeff == 1 || coeff == -1)) //if coefficient is positive out + sign in front
    {
        cout << " + ";
        if (exp == 1) //if exp is one then exponent is not displayed
        {

            cout << coeff << "x";
        }

        else if (exp == 0) //if exp is zero then only coefifcient is displayed
        {
            cout << coeff;
        }
        else if (exp == -1)
        {
            cout << "";
        }

        else
        {

            cout << coeff << "x^" << exp;
        }


    }

    else if (coeff == 1) //if coefficient is positive out + sign in front
    {

        if (exp == 1) //if exp is one then exponent is not displayed
        {
            cout << " + ";
            cout<< "x";
        }

        else if (exp == 0) //if exp is zero then only coefifcient is displayed
        {
            cout << " + ";
            cout << coeff;
        }
        else if (exp == -1)
        {
            cout << "";
        }

        else
        {
            cout << " + ";
            cout << "x^" << exp;
        }


    }

    else if (coeff == -1) //if coefficient is positive out + sign in front
    {

        if (exp == 1) //if exp is one then exponent is not displayed
        {
            cout << " - ";
            cout << "x";
        }

        else if (exp == 0) //if exp is zero then only coefifcient is displayed
        {
            cout << " - ";
            cout << abs(coeff);
        }

        else if (exp == -1)
        {
            cout << "";
        }

        else
        {
            cout << " - ";
            cout << "x^" << exp;
        }


    }

    else if (coeff == 0)
    {
        cout << "";
    }

    else
    {
        cout << " + ";
        if (exp == 1) //if exp is one then exponent is not displayed
        {

            cout << "x";
        }

        else if (exp == 0) //if exp is zero then only coefifcient is displayed
        {
            cout << "";
        }

        else
        {

            cout << "x^" << exp;
        }


    }

}

// CLASS POLY MEMBER FUNCTIONS
Term Poly::getTerm(const int index) const //return the term in the instance variable terms located at specific index
{
    // Replace with your code
    return terms[index];

}

int Poly::degree() const // returns the largest exponent in the list
{
    // Replace with your code
    Term largest;

    largest = terms[0];
    int large = largest.getExp();

    return large;

}

int Poly::termCount() const //returns the number of terms in the polynomial
{
    // Replace with your code
    int numTerms = terms.size();

    return numTerms;

}

void Poly::addTerm(const int coeff, const int exp) //adds a term to the list terms given coefficient and exponent
{
    // Replace with your code
    Term add;

    add.setCoeff(coeff);
    add.getCoeff();
    add.setExp(exp);
    add.getCoeff();

    terms.push_back(add);
}

void Poly::scale(const int fact) //change sthe polynomial by multiplying each term with a scale factor is is passed into the function
{
    // Replace with your code



    if (fact == 0) //if scale is zero
    {
        for (int i = 0; i < termCount(); i++)
        {

            terms[i].setCoeff(0);
            terms[i].setExp(0);


        }
    }


    else
    {

        for (int i = 0; i < termCount(); i++)
        {

            terms[i].setCoeff(fact * getTerm(i).getCoeff());


        }

    }
}

double Poly::eval(const double x) const //evaluates the polynommial given an input value for vriable x
{
    // Replace with your code
    double evaluation1 = 0; //initializes the total

    for (int i = 0; i < termCount(); i++)
    {
        evaluation1 = evaluation1 + getTerm(i).eval(x);
    }


    return evaluation1;
}

Poly Poly::derivative() const //returns a polynomial that is the derivative of the polynomial it is called on
{
    // Replace with your code
    Poly deriv;

    for (int i = 0; i < termCount(); i++)
    {
        deriv.getTerm(i).derivative();
    }

    return deriv;




}

void Poly::display(const string & label) const //prints a label and then prints the polynomial to the screen in a readable format
{
    // Replace with your code
    cout << label; //prints label

    getTerm(0).displayFirst();

    for (int i = 1; i < termCount(); i++)
    {
        getTerm(i).displayNext();
    }

    cout << endl;


}

void Poly::displayMultiply(const Poly & poly, const string & label) const
//parameters are polynomial passed in as an input paramter (polynomial B) and label
{
    // Replace with your code
    cout << label << ":   "; //print label

    getTerm(0).multiply(poly.getTerm(0)).displayFirst();


    for (int j = 1; j < poly.termCount(); j++)
        {
            getTerm(0).multiply(poly.getTerm(j)).displayNext();
        }




    for (int i = 1; i < termCount(); i++)
    {


        for (int j = 0; j < poly.termCount(); j++)
        {
            getTerm(i).multiply(poly.getTerm(j)).displayNext();
        }

    }

    cout << endl;

}

// NON-MEMBER FUNCTIONS
void display_banner() { //prints the welcome banner
    // Replace with your code
    cout << "Welcome to fun with polynomials!" << endl;
    cout << "You will enter two polynomials." << endl;
    cout << "Please follow all instructions below" << endl;
    cout << endl;
}

Poly read_poly(const int label) //prompts then reads a polynomial from the user one term per line
{
    // Replace with your code
    Poly vpoly;
    int coeff, exp, min(-1);
    bool first_term(false);
    cout << "Enter poly #" << label << endl;
    cin >> coeff >> exp;

    if (coeff == 0 && exp == 0) //if coefficient and exponent 0
    {
        vpoly.addTerm(coeff, exp); //add zero to polynomial and end
    }
    else {
        while (exp != 0) //while exponent does not equal to zero
        {
            if (exp < 0 || (coeff != 0 && (exp >= min && min != -1))) //if exponent is less that zero or (coefficient is not zero and (exponent is greater than -1 and minimum doesn't equal -1)
            {
                cerr << "polynomial entered wrong." << endl;
                exit(0);
            }

            if (coeff != 0) //if coefficent is not zero
            {
                first_term = true;
                min = exp;
                vpoly.addTerm(coeff, exp);
            }

            cin >> coeff >> exp;
        } //end of while
        if (coeff != 0 || (!(first_term) && coeff == 0)) //if coefficient does not equal zero or (first term and coefficient does not equal zero)
        {
            vpoly.addTerm(coeff, exp);
        } // end of else


    }

    return vpoly;

}

void display_stats(const Poly & poly, const string & label) //displays the information for a polynomial including the polynomial in a readabble format
{
    // Replace with your code

    poly.display(label);
    cout << "The polynomial has degree " << poly.degree() << endl;
    cout << "The polynomial has " << poly.termCount() << " Terms" <<  endl;
    cout << "The derivative is ";

    poly.getTerm(0).derivative().displayFirst();

    for (int i = 1; i < poly.termCount(); i++)
    {
        poly.getTerm(i).derivative().displayNext();
    }

    cout << endl;
    cout << endl; //creates blank line


}

void evaluate_poly(const Poly & poly) //prompts the user to enter how many values to evaluate
{
    // Replace with your code
    int x, times; //initalizes evaluation and the number of times user wants to evaluate
    cout << "How many times would you like evaluate with the first polynomial?  ";
    cin >> times;

    for (int i = 1; i <= times; i++)
    {
        cout << "Enter value to evaluate: ";
        cin >> x;

        cout << "	When x = " << x << " " << "The polynomial evaluates to " << poly.eval(x); //prints evaluation
        cout << endl;

    }



}


void goodbye_banner() //prints goodbye message
{
    // Replace with your code
    cout << "Thank you for playing!" << endl;
}
