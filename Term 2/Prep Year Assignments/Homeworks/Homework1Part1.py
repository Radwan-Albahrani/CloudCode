# Creating list of countries
import pycountry
countries = pycountry.countries

# Creating a list of months
months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

# Saving the string to a variable
Data = "Saudi Arabia traces its roots back to the earliest civilizations of the Arabian Peninsula. On September 23, 1932, King Abdulaziz Al-Saud established the Kingdom of Saudi Arabia, an Islamic state with Arabic as its national language and the Holy Qur’an as its constitution."

# Getting The country in the string
for country in countries:
    if country.name in Data:
        country = country.name
        break

# Getting the Date
for month in months:
    if month in Data:
        index = Data.index(month)
        FoundDate = Data[index:index+30]
        break
        


# Removing any Excess from the date
FoundDate = FoundDate.split(",")
FoundDate.pop()
FoundDate = ",".join(FoundDate)

# Getting the civilization
for civil in ["Arabian Peninsula"]:
    if civil in Data:
        index = Data.index(civil)
        FoundCivil = Data[index:index+20]

# Cleaning it
FoundCivil = FoundCivil.split(".")
FoundCivil.pop()
FoundCivil = " ".join(FoundCivil)

# Getting the King
for king in ["King Abdulaziz Al-Saud"]:
    if king in Data:
        index = Data.index(king)
        FoundKing = Data[index:index+23]


# Printing Data
print(f"""
Total Characters in this Paragraph: {str(len(Data))}
Country:            {country}
Civilization:       {FoundCivil}
Established on:     {FoundDate}
Establishes by:     {FoundKing}
"""
)

# Done :)