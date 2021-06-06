#include <iostream> 
#include <stdexcept> 
#include "stack.h"
#include <cstring>

using namespace std;

int main()
{
    stack* p_stack = NULL;
    data_t n_data = 0,choice = 0,ex_data = 0;
    string str;

    cout <<"\n================================= Stack =================================\n" << endl;
    do
    {
               cout << "\n1.Create Stack. \n2.Push. \n3.Pop. \n4.Find. \n5.Show Stack. \n6.Destory Stack. \n7.Exit. \n\nEnter Your Choice =  ";
               cin >> choice;

               if(p_stack == NULL && (choice <= 6 && choice >= 2))
               {
                  cout << "\nStack is Not Created First Create a Stack\n" << endl;
                  continue;
               }

               switch(choice)
               {
                      case 1:                        
                           if(p_stack == NULL)
                           {
                                cout << "\nEnter the no. of element in  stack = ";
                                cin >> n_data;

                                try
                                {
                                    p_stack = new stack(n_data);
                                      cout << "\nStack is Created Successfully...\n" << endl;
                               }catch(neg_size& e)
                               {
                                    cout << e.what() << endl;
                               }                               
                           }
                           else
                           {
                                cout << "\nStack is already Created..\n" << endl;
                           }
                      break;


                      case 2:
                             cout << "\nEnter New Data = ";
                             cin >> n_data;

                             try
                             {
                                if(p_stack->push(n_data)) 
                                   cout <<"\nData Inserted Successfully....\n" << endl; 
                             }catch(stack_full& e)
                             {
                                 cout << e.what() << endl;
                             } 
                      break;


                        case 3:        
                                
                                 try
                                 {
                                     p_stack->pop(&ex_data);
                                     cout << "\nPoped Data = " << ex_data << endl;
                                 }catch(is_empty_stack& e)
                                 {
                                     cout << e.what() << endl;
                                 }

                        break;

                                        

                        case 4:
                                    cout <<"\nEnter data  =  ";
                                    cin >> ex_data;
                                     
                                    try
                                    {
                                         if(p_stack->find_data(ex_data))
                                            cout << ex_data <<  " is present in Stack" << endl;

                                    }catch(stack_data_not_found& e)
                                    {
                                        cout << e.what() << endl;
                                    }                                 
                        break;

                        
                        case 5:
                            
                             try
                            {
                               cout << *p_stack;

                            }catch(is_empty_stack& e)
                            {
                                 cout << e.what() << endl;
                            }
                                    
                        break;

                       
                        case 6:
                             cout <<"\nAre you sure to Delete a Complete Stack[Yes/No] = ";
                             cin >> str;
     
                             if(str.compare("Yes") == 0 || str.compare("YES") == 0 || str.compare("yes") == 0)
                             {
                                delete p_stack;
                                p_stack = NULL;
                                   cout <<"\nStack is Destroyed Successfully.....\n" << endl;
                             }
                             else if(str.compare("No") == 0 || str.compare("NO") == 0 || str.compare("no") == 0)
                             {
                                   cout <<"\nOk....\n" << endl;
                             }
                             else
                             {
                                    cout <<"\nPlease Enter Correct Choice\n" << endl;
                             }
                        break;


                        case 7:
                            if(p_stack != NULL)
                                delete p_stack;

                             p_stack = NULL;
                             cout << "\nThank You.....\n\n" << endl;
                             return (0);
                        break;


                        default:
                            cout << "\nYou Entered Wrong Choice, Please Enter correct choice..\n" << endl;
                        break;
  
                }

    }while(1);

    return(0);
}



