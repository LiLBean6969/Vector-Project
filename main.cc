#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
/*
Name:Roberto Velazquez
CWID:885666107
*/

template <typename T>
class Item {
public:
    T name;
    T expiration;
    T category;
    int quantity;
    Item(T n, T e, T c, int q) {
        name = n;
        expiration = e;
        category = c;
        quantity = q;
    }
};

template<typename T>
class Inventory {
private:
    std::vector<Item<T>> items;
public:
    void addNewItem(Item<T> item) {
        for (const auto& it : items) {
            if (it.name == item.name) {
                std::cout << "Item is already present in inventory" << std::endl;
                return;
            }
        }
        items.push_back(item);
    }

    void increaseQuantity(T itemname, int quantity) {
        for (auto& item : items) {
            if (item.name == itemname) {
                item.quantity += quantity;
                return;
            }
        }
    }

    void updateItem(T itemname, T expiration, int quantity, T category) {
        for (auto& item : items) {
            if (item.name == itemname) {
                item.expiration = expiration;
                item.quantity += quantity;
                item.category = category;
                return;
            }
        }
    }

    void removeItem(T itemname) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->name == itemname) {
                items.erase(it);
                return;
            }
        }
    }

    int Total() {
        int total = 0;
        for (const auto& item : items) {
            total += item.quantity;
        }
        return total;
    }

void searchItem(T itemname) {
    for (const auto& item : items) {
        if (item.name == itemname) {
            std::cout << "Query for " << itemname << std::endl;
            std::cout << "Item = " << item.name << std::endl;
            std::cout << "Expiration Date = " << item.expiration << std::endl;
            std::cout << "Category = " << item.category << std::endl;
            std::cout << "Quantity = " << item.quantity << std::endl;
            return;
        }
    }
    throw "Item not found!!";
}

    void displayItems() {
        std::cout << "-------Inventory-------" << std::endl;
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Expiration" << std::setw(15)
            << "Quantity" << std::setw(10) << "Category" << std::endl;
        for (int i = 0; i < items.size(); i++) {
            std::cout << std::left <<
                std::setw(20) << items[i].name << std::setw(15) << items[i].expiration << std::setw(15) << items[i].quantity << std::setw(15) << items[i].category << std::endl;
        }
    }
};

template<typename T>
class Appointment {
public:
    T c_name;
    T ap_date;
    T ap_time;
    T CWID;
    Appointment(T n, T d, T t, T cw) {
        c_name = n;
        ap_date = d;
        ap_time = t;
        CWID = cw;
    }
};

template<typename T>
class AppointmentSystem {
private:
    std::vector<Appointment<T>> ap;
public:
    void schedule(Appointment<T> appointment) {
        for (const auto& a : ap) {
            if (a.CWID == appointment.CWID) {
                std::cout << "You have already scheduled an appointment!!!" << std::endl;
                return;
            }
        }
        ap.push_back(appointment);
    }

    void Total_appointments(T date, T time) {
        int total = 0;
        for (const auto& a : ap) {
            if (a.ap_date == date) {
                total++;
            }
        }
        std::cout << "Total appointments on " << date << ":  " << total << std::endl;
    }

    void removeRecent() {
        if (!ap.empty()) {
            ap.pop_back();
        }
    }

    void display() {
        std::cout << "------Appointments-----" << std::endl;
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Date" << std::setw(15)
            << "Time" << std::setw(15) << "CWID" << std::endl;
        for (int i = 0; i < ap.size(); i++) {
            std::cout << std::left <<
                std::setw(20) << ap[i].c_name << std::setw(15) << ap[i].ap_date << std::setw(15) << ap[i].ap_time << std::setw(15) << ap[i].CWID << std::endl;
        }
    }
};
int main() {
    Inventory<std::string> i1;
    Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    std::cout << "Quantity has increased by: " << 4 << " above the inventory" << std::endl;
    std::cout << "Total number of items: " << i1.Total() << std::endl;

    Item<std::string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    std::cout << "Quantity has increased by: " << 2 << " above the inventory" << std::endl;
    std::cout << "Total number of items: " << i1.Total() << std::endl;

    Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    std::cout << "Quantity has increased by: " << 5 << " above the inventory" << std::endl;
    std::cout << "Total number of items: " << i1.Total() << std::endl;

    i1.displayItems();

    i1.updateItem("Milk","09/24/2023",3,"Regular");
    std::cout << "Updated Milk" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Total number of items: " << i1.Total() << std::endl;
    i1.displayItems();

    i1.increaseQuantity("Cerels",10);
    std::cout << "Increased quantity of Cerels by: " << 10 << std::endl;
    std::cout << "Total number of items: " << i1.Total() << std::endl;
    i1.displayItems();

    try {
        i1.updateItem("bar", "09/12/2023", 3, "Snacks");
    }
    catch(const char* msg) {
        std::cout << msg << std::endl;
    }
    i1.displayItems();

    try {
        i1.updateItem("Cerels","09/27/2023",4,"Regular");
    }
    catch(const char* msg) {
        std::cout << msg << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
    std::cout << "Total number of items: " << i1.Total() << std::endl;
    i1.displayItems();

    try {
        i1.removeItem("Bread");
    }
    catch(const char* msg) {
        std::cout << msg << std::endl;
    }

    try {
        i1.removeItem("Milk");
    }
    catch(const char* msg) {
        std::cout << msg << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
    std::cout << "Total number of items: " << i1.Total() << std::endl;
    i1.displayItems();

    std::cout << "-----------------------" << std::endl;

    try {
        i1.searchItem("Cerels");
    }
    catch(const char* msg) {
        std::cout << msg << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
    AppointmentSystem<std::string> s1;
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");

    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);

    std::string date = "09/12/2023";
    std::string time = "12:00PM";
    s1.Total_appointments(date, time);

    s1.display();

    return 0;
}
