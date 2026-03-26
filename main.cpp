#include <iostream>
#include <windows.h>
using namespace std;

const int max_options_in_menu = 5;
int N = 0; //chislo za razmer na masiwa
bool input_choice_counter = 0; //prowerka dali e izbrana pyrwa opciq(input) za da ne mozhe da se izbere pyrwona4alno za izwezhdane
bool evens_choice_counter = 0;
bool sortin_choice_counter = 0;
int AN[30];
int AS[30];
int an_index = 0;
int index_for_as = 0;
double sum = 0;


int menu()
{
    int izbor = 0;

    do{
        cout << "menu \n\n";
        cout << "izberete opciq \n\n";
        cout << "1. wywezhdane na masiw \n";
        cout << "2. izwezhdane na chetnite chisla \n";
        cout << "3. sortirane w nizhodqsht red\n";
        cout << "4. izwezhdane na wsichki masiwi\n";
        cout << "5. izhod ot programata\n";
        cin >> izbor;
    }while(izbor <1 || izbor > max_options_in_menu);
    return izbor;
}

int input_array(int arr[], const unsigned int size)
{
    input_choice_counter = 1;
    evens_choice_counter = 0;
    sortin_choice_counter = 0;
    an_index = 0;
    index_for_as = 0;
    sum = 0;

    cout << "wywedete razmernost na masiwa(mezhdu 2 i 30 elementa): \n";
    do{
    cin >> N;
    }while (N < 2 || N > 30);


        for(int i = 0; i < N; i++){
         do{
            cout <<"arr[" << i << "]= ";
            cin >> arr[i];
         }while(arr[i] < 0 || arr[i] > 9000 );
        }

    return 0;
}

void print_arrays(const int arr[], const unsigned int size)
{

    if(input_choice_counter > 0 && evens_choice_counter > 0 && sortin_choice_counter > 0)
    {
        cout << "masiwite sa: \n\n\n";
        cout << "wyweden masiw: \n\n";
        for(int i = 0; i < N; i++)
        {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }

        cout << endl << "masiw  AN(K) ot chetnite chisla na arr: \n";
        for(int i = 0; i < an_index; i++)
        {
            cout << "AN[" << i << "] = " << AN[i] << endl;
        }

        cout << endl << "i sredno aritmetichnoto ot elementite im- avg. = " << sum / an_index  << endl;

        cout << endl << "masiw za sortirane AS(K):" << endl;
        for(int i = 0; i < N; i++)
        {
          cout << AS[i] << endl;
        }

        cout << endl << "i sled sortirane w nizhodqsht red:" << endl;
        for(int i = 0; i < N - 1; i++)
        {
            for(int index_for_as = 0; index_for_as < N - i - 1; index_for_as++)
            {
                if(AS[index_for_as] < AS[index_for_as + 1])
                {
                    int buff = AS[index_for_as];
                    AS[index_for_as] = AS[index_for_as + 1];
                    AS[index_for_as + 1] = buff;
                }
            }
        }

        for(int i = 0; i < N; i++)
        {
            cout << "AS[" << index_for_as << "] = "   << AS[i] << endl;
        }




    }else cout << "molq wyrnete se w menuto, wywedete masiw i go obrabotete. \n";
}

void evens_avg(int arr[], const unsigned int size)
{
 if(input_choice_counter > 0)
    {
    evens_choice_counter = 1;
    sum = 0;
    cout << "nowiq masiw AN(K) ot chetnite chisla na arr[i] e: \n";
    for(int i = 0; i < N; i++)
    {
        if(arr[i]%2 == 0)
        {AN[an_index] = arr[i];
        cout << "AN[" << an_index << "] = " << AN[an_index] << endl;
        an_index++;
        }
    }

    for(int i = 0; i < an_index; i++)
    {
        sum+=AN[i];
    }

    cout << "\n\nsredno aritmetichnoto ot tezi chisla e " << sum << "/" << an_index << " = " << sum / an_index << endl << endl << endl;


    }else cout << "molq wyrnete se w menuto i wywedete masiw. \n";
}

void sortin(int arr[], const unsigned int size)
{
    if(input_choice_counter > 0)
    {
    sortin_choice_counter = 1;
    for(int i = 0; i < N; i++)
    {
        AS[index_for_as] = arr[i];
        cout << "AS[" << index_for_as << "] = "   << AS[i] << endl;
        index_for_as++;

    }

    cout << endl << "i sled sortirane w nizhodqsht red:" << endl;
        for(int i = 0; i < N - 1; i++)
        {
            for(int index_for_as = 0; index_for_as < N - i - 1; index_for_as++)
            {
                if(AS[index_for_as] < AS[index_for_as + 1])
                {
                    int buff = AS[index_for_as];
                    AS[index_for_as] = AS[index_for_as + 1];
                    AS[index_for_as + 1] = buff;
                }
            }
        }

        for(int i = 0; i < N; i++)
        {
            cout << "AS[" << index_for_as << "] = "   << AS[i] << endl;
        }
        }else cout << "molq wyrnete se w menuto i wywedete masiw. \n";
}


int main()
{
    system("color 0a"); //zileno
    int menuopcia = 0; //priswoqwa stoinostta ot resultata ot int menu -1, 2 ili 3
    int arr[30];
    do
    {
        menuopcia = menu();
        system("cls"); //clear screen, iztriva menuto sled izbor na opciq

        switch(menuopcia) // w zawisimost ot twa kwo e priswoila menuopcia se izpylnqwa ili input, output ili izhod
        {
            case 1: input_array(arr, N); break;
            case 4: print_arrays(arr, N); break;
            case 2: evens_avg(arr, N); break;
            case 3: sortin(arr, N); break;
            case 5: cout << "krai na programata \n\n"; break;
        }
        system ("pause"); // 4aka dokat se natisne buton
        system ("cls");
    } while(menuopcia < max_options_in_menu);


    return 0;
}
