import json
from validate_json import *
from manage_json import *

def menu():
    print("--- Wybierz ---")
    print("1) Classes")
    print("2) Items")
    print("3) Monsters")
    print("4) exit")
    print("---------------")

def menu2(name):
    print(f"--- {name} ---")
    print("1) Wyświetl dane")
    print("2) Sprawdź dane")
    print("3) Dodaj dane")
    print("4) Edytuj dane")
    print("5) Usuń dane")
    print("6) exit")
    print("---------------")

def main():
    menu()
    while True:
        choice = input("Wybierz opcje: ")
        choice = choice.strip()
        if choice == "1":
            user_pick("Classes")  
        elif choice == "2":
            user_pick("Items")
        elif choice == "3":
            validate_monsters()
            user_pick("Monsters")
        elif choice == "4":
            print("Adios!")
            break
        else:
            print("Nieprawidłowa opcja. Spróbuj ponownie.")   
            menu() 

def user_pick(name):
    menu2(name)
    while True:
        choice = input("Wybierz opcje: ")
        choice = choice.strip()
        if choice == "1":
            show_data(name)
            menu2(name)  
        elif choice == "2":
            validate_data(name)
            menu2(name)
        elif choice == "3":
            menu2(name)
        elif choice == "4":
            menu2(name)
        elif choice == "5":
            menu2(name)
        elif choice == "6":
            menu()
            break
        else:
            print("Nieprawidłowa opcja. Spróbuj ponownie.")   
            menu2(name) 

if __name__ == "__main__":
    main()