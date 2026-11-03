import json

def menu():
    print("--- Walidacja ---")
    print("1) Classes")
    print("2) Items")
    print("3) Monsters")
    print("4) exit")
    print("-----------------")


def validate_classes():

    result = True
    
    with open("data/Classes.json", "r") as file:
        try:
            object = json.load(file)
        except json.JSONDecodeError as e:
            print(f"Niepoprawna składnia w {e.lineno} linii")
            return

        classes_str = ["name", "description"]
        classes_dict = ["baseStats", "statGrowth"]
        classes_int = ["hp", "mana", "damage", "defense"]
        found_ids = set()

        for each in object["classes"]:
            klasa_id = each.get("id", "BRAK_ID")

            #### CHECKER FOR ID FIELD
            if "id" not in each:
                print(f"Błąd w (ID: {klasa_id}): Brak pola 'id'")
                result = False
            elif isinstance(each.get("id"), int) and each["id"] <= 0:
                print(f"Nieprawidłowe ID ({each['id']}) | oczekiwano int > 0")
                result = False
            elif each["id"] in found_ids:
                print(f"Błąd w (ID: {klasa_id}): Duplikat ID")
                result = False
            else:
                found_ids.add(each["id"])

            #### CHECKER FOR STRING FIELDS
            for field_str in classes_str:
                if field_str not in each:
                    print(f"Błąd w (ID: {klasa_id}): Brak '{field_str}'")
                    result = False
                elif not isinstance(each[field_str], str) or not each[field_str]:
                    print(f"Błąd w (ID: {klasa_id}): '{field_str}' | oczekiwano niepustego stringa")
                    result = False

            #### CHECKER FOR DICTIONARY FIELDS
            for field_dict in classes_dict:
                if field_dict not in each:
                    print(f"Błąd w (ID: {klasa_id}): Brak '{field_dict}'")
                    result = False
                elif not isinstance(each[field_dict], dict) or not each[field_dict]:
                    print(f"Błąd w ID: {klasa_id}): '{field_dict}' | oczekiwano niepustego słownika")
                    result = False

            #### CHECKER FOR INT FIELDS IN DICTIONARY
            for field_dict_int in classes_dict:
                section = each.get(field_dict_int, {})
                if isinstance(section, dict): 
                    for stat in classes_int:
                        val = section.get(stat)
                        if val is None or not isinstance(val, int):
                            print(f"Błąd w (ID: {klasa_id}) -> '{field_dict_int}': Niepoprawna wartość '{stat}' ({val}) | oczekiwano int")
                            result = False
                        elif val < 0:
                            print(f"Błąd w (ID: {klasa_id}) -> '{field_dict_int}': Ujemna wartość '{stat}' ({val})")
                            result = False

    if result:
        print("Plik classes.json jest poprawny.")

def validate_items():
    result = True
    with open("data/Items.json", "r") as file:
        try:
            object = json.load(file)
        except json.JSONDecodeError as e:
            print(f"Niepoprawna składnia w {e.lineno} linii")
            return
        
        items_str = ["name", "description", "type"]
        items_int = ["id", "maxStack", "damage", "defense", "value", "healAmount"]
        found_ids = set()

        for each in object["items"]:
            item_id = each.get("id", "BRAK_ID")
    
            #### CHECKER FOR ID FIELD
            if "id" not in each:
                print(f"Błąd w (ID: {item_id}): Brak pola 'id'")
                result = False
            elif isinstance(each.get("id"), int) and each["id"] <= 0:
                print(f"Nieprawidłowe ID ({each['id']}) | oczekiwano int > 0")
                result = False
            elif each["id"] in found_ids:
                print(f"Błąd w (ID: {item_id}): Duplikat ID")
                result = False
            else:
                found_ids.add(each["id"])

            #### CHECKER FOR BOOL FIELD
            if "stackable" not in each:
                print(f"Błąd w (ID: {item_id}): 'stackable' Brak")
            elif not isinstance(each.get("stackable"), bool):
                print(f"Błąd w (ID: {item_id}): 'stackable' powinien być typu bool")
                result = False 

            #### CHECKER FOR STRING FIELDS
            for field_str in items_str:
                if field_str not in each or not each[field_str]:
                    print(f"Błąd w (ID: {item_id}): Brak lub puste field_str '{field_str}'")
                elif not isinstance(each[field_str], str):
                    print(f"Błąd w (ID: {item_id}): {field_str} powinien być typu string")
                    result = False

            #### CHECKER FOR INT FIELDS
            for field_int in items_int:
                if each["type"] == "Consumable" and field_int in ["damage", "defense"]:
                    continue

                if each["type"] != "Consumable" and field_int in ["healAmount"]:
                    continue

                if field_int not in each:
                    print(f"Błąd w (ID: {item_id}): Brak pola '{field_int}'")
                    result = False
                elif not isinstance(each[field_int], int):
                    print(f"Błąd w (ID: {item_id}): {field_int} powinien być typu int")
                    result = False
                elif each[field_int] < 0:
                    print(f"Błąd w (ID: {item_id}): {field_int} powinien być większy lub równy 0")
                    result = False

    if result:
        print("Plik items.json jest poprawny.")

def validate_monsters():
    result = True
    with open("data/Monsters.json", "r") as file:
        try:
            object = json.load(file)
        except json.JSONDecodeError as e:
            print(f"Niepoprawna składnia w {e.lineno} linii")
            return
        
        monster_str = ["name", "description"]
        monster_int = ["level", "hp", "damage", "defense", "experienceReward", "goldReward"]
        found_ids = set()

        for each in object["monsters"]:
            monster_id = each.get("id", "BRAK_ID")
            
            #### CHECKER FOR ID FIELD
            if "id" not in each:
                print(f"Błąd w (ID: {monster_id}): Brak pola 'id'")
                result = False
            elif isinstance(each.get("id"), int) and each["id"] <= 0:
                print(f"Nieprawidłowe ID ({each['id']}) | oczekiwano int > 0")
                result = False
            elif each["id"] in found_ids:
                print(f"Błąd w (ID: {monster_id}): Duplikat ID")
                result = False
            else:
                found_ids.add(each["id"])

            #### CHECKER FOR STRING FIELDS
            for field_str in monster_str:
                if field_str not in each:
                    print(f"Błąd w (ID: {monster_id}): Brak '{field_str}'")
                    result = False
                elif not isinstance(each[field_str], str) or not each[field_str]:
                    print(f"Błąd w (ID: {monster_id}): {field_str} | oczekiwano niepustego stringa")
                    result = False

            #### CHECKER FOR INT FIELDS
            for field_int in monster_int:
                if field_int not in each:
                    print(f"Błąd w (ID: {monster_id}): Brak pola '{field_int}'")
                    result = False
                elif not isinstance(each[field_int], int) or each[field_int] < 0:
                    print(f"Błąd w (ID: {monster_id}): {field_int} | oczekiwano int >= 0")
                    result = False

            ### CHECKER FOR INT IN DICTOINARY
            drop_table = each.get("dropTable")

            if drop_table is not None:
                if not isinstance(drop_table, list):
                    print(f"Błąd w (ID: {monster_id}): 'dropTable' | oczekiwano liste")
                    result = False
                else:
                    for drop_item in drop_table:
                        item_id = drop_item.get("itemId")
                        if item_id is None or not isinstance(item_id, int) or item_id < 0:
                            print(f"Błąd w (ID: {monster_id}): dropTable[itemId] | oczekiwano int > 0")
                            result = False
                            
                        chance = drop_item.get("dropChance")
                        if chance is None:
                            print(f"Błąd w (ID: {monster_id}): Brak pola 'dropTable[dropChance]'")
                            result = False
                        elif not isinstance(chance, float) or not (0.0 <= chance <= 1.0):
                            print(f"Błąd w (ID: {monster_id}): dropTable[dropChance] | oczekiwano 0 <= float >= 1")
                            result = False
    if result:
        print("Plik monsters.json jest poprawny.")

def main():
    menu()
    while True:
        choice = input("Wybierz opcje: ")
        choice = choice.strip()
        if choice == "1":
            validate_classes()
            menu()  
        elif choice == "2":
            validate_items()
            menu()

        elif choice == "3":
            validate_monsters()
            menu()
        
        elif choice == "4":
            print("Adios!")
            break
        else:
            print("Nieprawidłowa opcja. Spróbuj ponownie.")   
            menu() 

if __name__ == "__main__":
    main()