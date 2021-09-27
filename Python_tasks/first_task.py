import collections
from numpy import NaN, arange, number, sqrt
import numpy
from numpy.core.numeric import full
from numpy.lib.function_base import copy, median
import pandas
import math
import statistics


data = pandas.read_csv('titanic.csv', index_col='PassengerId')



#first task
female_number = male_number = 0
for human in data['Sex']:
    if (human == 'female'):
        female_number = female_number + 1
    elif (human == 'male'):
        male_number = male_number + 1
print(f"Male number = {male_number}, female number = {female_number}")



#second task
number_of_survived = 0

for did_survive in data['Survived']:
    if (did_survive == 1):
        number_of_survived = number_of_survived + 1

percentage_of_survivors = round(round(number_of_survived / (female_number + male_number),4)*100,2)
print(f"Percentage of survivors - {percentage_of_survivors}")



#third task
number_of_first_class_passengers = 0

for class_number in data['Pclass']:
    if (class_number == 1):
        number_of_first_class_passengers += 1

Percentage_of_first_class_pass = round(round(number_of_first_class_passengers / (female_number + male_number),4)*100,2)
print(f'Percentage of first class passengers - {Percentage_of_first_class_pass}')



#fourth task
middle_age = 0
new_array = (data['Age'])[~numpy.isnan(data['Age'])]

middle_age = numpy.sum(new_array)

print(f"Middle age - {round(middle_age / (female_number + male_number),2)} ")

median_ = median(new_array)

print(f"Median - {median_}")


#fifth task,Pearcon correlation coefficient computing


#Simple way 
coeff = numpy.corrcoef(data['SibSp'],data['Parch'])
print(f"Coeff matrix - {coeff} ")

#Without corrcoef method
middle_SibSp = numpy.sum(data['SibSp']) / (female_number + male_number)
middle_Parch = numpy.sum(data['Parch']) / (female_number + male_number)

#d_x array computing
SibSp_correlation = [SibSp_elem - middle_SibSp for SibSp_elem in data['SibSp']]

#d_y array computing
Parch_correlation = [Parch_elem - middle_Parch for Parch_elem in data['Parch']]

sum = 0
for index in range(len(SibSp_correlation)):
    sum += SibSp_correlation[index] * Parch_correlation[index]

sqr_sum_x = numpy.sum([d_x**2 for d_x in SibSp_correlation])
sqr_sum_y = numpy.sum([d_y**2 for d_y in Parch_correlation])

result_sqr_sum = sqrt(sqr_sum_x * sqr_sum_y)

print(f"Correlation coefficient = {sum / result_sqr_sum}")

"""

sixth task,find most popular female first name
string format - " second_name,Mr/Mrs/Master/Miss first_name "
 
"""

array_with_female_names = [full_name[full_name.find('(') + 1:full_name.rfind(' ')] for full_name in data['Name'] if full_name.find('Mrs') != -1]
array_with_female_names.insert(0,[full_name[full_name.find('Miss') + len('Miss') + 2:] for full_name in data['Name'] if full_name.find('Miss') != -1])

name_keys = {'Helena': 0, 'Maria': 0, 'Anna':0, 'Ekaterina':0 , 'Margarita':0 , 'Liza':0}

for name in array_with_female_names:
    if('Helen' in name):
        name_keys['Helena'] += 1
    elif('eli' in name):
        name_keys['Helena'] += 1
    elif('mari' in name):
        name_keys['Maria'] += 1
    elif('Mari' in name):
        name_keys['Maria'] += 1
    elif('Mary' or 'mary' in name):
        name_keys['Maria'] += 1
    elif('Ann' or 'ann' in name):
        name_keys['Anna'] += 1
    elif('Kat' or 'kat' in name):
        name_keys['Ekaterina'] += 1
    elif('Marg' or 'marg' in name):
        name_keys['Margarita'] += 1
    elif('Liz' or 'liz' in name):
        name_keys['Liza'] += 1

print(f"Most popular name - {max(name_keys, key=name_keys.get)}")
        
