--get data about all teachers
SELECT * FROM teacher;

--get data abount all student groups where speciality is ECM 
SELECT * FROM student_group
WHERE speciality = 'ЭВМ';

--get teacher personal key number and audience number where subject with number '18П' is taught
SELECT personal_number, audience_number
FROM teacher_teaches_subjects_in_groups
WHERE subject_number = '18П'

--get subject number and name which are taught by 'Kostin' teacher
SELECT DISTINCT teacher_teaches_subjects_in_groups.subject_number, subject.subject_name
FROM teacher 
INNER JOIN teacher_teaches_subjects_in_groups
ON teacher.personal_number = teacher_teaches_subjects_in_groups.personal_number
INNER JOIN subject
ON teacher_teaches_subjects_in_groups.subject_number = subject.subject_number
WHERE teacher.surname = 'Костин'

--get groups number in which 'Frolov' teacher teaches
SELECT DISTINCT subject_number
FROM teacher_teaches_subjects_in_groups
INNER JOIN teacher USING(personal_number)
WHERE teacher.surname = 'Фролов'

--get information about the subjects that are conducted in the specialty of ASOI
SELECT *
FROM subject
WHERE speciality = 'АСОИ';

--get information about teachers who teach subjects in the specialty of ASOI
SElECT *
FROM teacher
WHERE CHARINDEX('АСОИ', speciality) != 0

--get the names of teachers who teach subjects in 210 classrooms.
SELECT DISTINCT surname 
FROM teacher
INNER JOIN teacher_teaches_subjects_in_groups USING(personal_number)
WHERE audience_number = 210

--get the names of subjects and the names of groups that teach classes in classrooms from 100 to 200.
SELECT subject_name, student_group.group_name
FROM subject
INNER JOIN teacher_teaches_subjects_in_groups USING(subject_number)
INNER JOIN student_group USING(group_number)
WHERE teacher_teaches_subjects_in_groups.audience_number BETWEEN 100 AND 200

--Get pairs of group numbers from the same specialty.


--find the total number of student with ECM speciality
SELECT SUM(number_of_people)
FROM student_group
WHERE speciality = 'ЭВМ'

--get the numbers of teachers teaching students in the ECM specialty.
SELECT personal_number
FROM teacher
WHERE CHARINDEX('ЭВМ', speciality) != 0
