import json

def show_data(name):

    data_name = name.capitalize()
    path = f"data/{data_name}.json"

    with open(path, "r") as file:
        data = json.load(file)
        
    formatted_json = json.dumps(data, indent=2)
    print(formatted_json)