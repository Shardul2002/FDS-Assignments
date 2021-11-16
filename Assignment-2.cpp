#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    int employee_id;
    string employee_name;
    int salary;
};

void add_record(Employee data[], int num)
{
    Employee *e = &data[0];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter Id of Employee" << (i + 1) << endl;
        cin >> e->employee_id;
        cout << "Enter Name of Employee" << (i + 1) << endl;
        cin >> e->employee_name;
        cout << "Enter Salary of Employee" << (i + 1) << endl;
        cin >> e->salary;
        e++;
    }
}

void display_record(Employee data[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << "Id :" << data[i].employee_id << endl;
        cout << "Employee name:" << data[i].employee_name << endl;
        cout << "Employee salary:" << data[i].salary << endl;
    }
}

int search_record(Employee arr[], int start, int end, int id)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid].employee_id == id)
        {
            return mid;
        }
        else if (arr[mid].employee_id > id)
        {
            return search_record(arr, start, (mid - 1), id);
        }
        else if (arr[mid].employee_id < id)
        {
            return search_record(arr, (mid + 1), end, id);
        }
    }
    return -1;
}

void delete_record(Employee data[], int delete_index, int &num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        if (data[i].employee_id == delete_index)
        {
            for (int j = i; j < num; j++)
            {
                data[j].employee_id = data[j + 1].employee_id;
                data[j].employee_name = data[j + 1].employee_name;
                data[j].salary = data[j + 1].salary;
            }
            num--;
        }
    }
}
int display_menu()
{
    int option;
    cout << "Choose option which you wish to perform" << endl;
    cout << "1.Add Record" << endl;
    cout << "2.Display record" << endl;
    cout << "3.Search record" << endl;
    cout << "4.Delete record" << endl;
    cout << "5.Exit" << endl;
    cin >> option;
    return option;
}

int main()
{
    int database;
    cout << "Enter size of database" << endl;

    cin >> database;
    struct Employee a[database];
    int option = -1;
    while (option != 5)
    {
        option = display_menu();
        switch (option)
        {
        case 1:
            int num;
            cout << "No of records to be added" << endl;
            cin >> num;
            add_record(a, num);
            break;

        case 2:
            display_record(a, num);
            cout << "\n";
            break;

        case 3:
            int id, index;
            cout << "Enter id to be searched" << endl;
            cin >> id;
            index = search_record(a, 0, num, id);
            if (index == -1)
            {
                cout << "The id is not present" << endl;
            }
            else
            {
                cout << "The Id is present!" << endl;
                cout << "Id:" << a[index].employee_id << endl;
                cout << "Name:" << a[index].employee_name << endl;
                cout << "Salary:" << a[index].salary << endl;
            }
            break;
        case 4:
            int id_del, delete_index;
            cout << "Enter ID to be deleted" << endl;
            cin >> id_del;
            // delete_index = search_record(a, 0, num, id_del);
            delete_record(a, id_del, num);
            cout << "\n";

            break;
        case 5:
            cout << "Existed Sucessfully!!" << endl;
            break;
        default:
            cout << "Invalid option!!" << endl;
            break;
        }
    }

    return 0;
}