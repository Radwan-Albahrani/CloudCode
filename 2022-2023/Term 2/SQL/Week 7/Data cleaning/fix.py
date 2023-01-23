import re
from datetime import datetime


string = ""
with open("Week 7\company-data.sql", "r") as f:
    string = f.read()

# regex to find date
reg = re.compile(r'\d{1,2}-\d{1,2}-\d{2,4}')

result = reg.findall(string)

formatted_dates = []
for date in result:
    try:
        d = datetime.strptime(date, "%d-%m-%y")
        formatted_date = d.strftime("%Y-%m-%d")
        if d.year > 2023:
            formatted_date = "19" + formatted_date[2:]
        formatted_dates.append(formatted_date)
    except ValueError:
        try:
            d = datetime.strptime(date, "%d-%m-%Y")
            formatted_dates.append(d.strftime("%Y-%m-%d"))
        except ValueError:
            print("Invalid date: {}".format(date))

for old_date, new_date in zip(result, formatted_dates):
    pattern = r"\b{}\b".format(old_date)
    string = re.sub(pattern, new_date, string)

with open("Week 7\data_inserting.sql", "w") as f:
    f.write(string)
