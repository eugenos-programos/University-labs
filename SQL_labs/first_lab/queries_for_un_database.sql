--1. get data about all teachers
SELECT * FROM teacher;

--2. get data about all student groups where speciality is ECM 
SELECT * FROM student_group
WHERE speciality = 'ЭВМ';

--3. get teacher personal key number and audience number where subject with number '18П' is taught
SELECT DISTINCT personal_number, audience_number
FROM teacher_teaches_subjects_in_groups
WHERE subject_number = '18П'

--4. get subject number and name which are taught by 'Kostin' teacher
SELECT DISTINCT teacher_teaches_subjects_in_groups.subject_number, subject.subject_name
FROM teacher 
INNER JOIN teacher_teaches_subjects_in_groups USING(personal_number)
INNER JOIN subject USING(subject_number)
WHERE teacher.surname = 'Костин'

--5. get groups number in which 'Frolov' teacher teaches
SELECT DISTINCT group_number
FROM teacher_teaches_subjects_in_groups
INNER JOIN teacher USING(personal_number)
WHERE teacher.surname = 'Фролов'

--6. get information about the subjects that are conducted in the specialty of ASOI
SELECT DISTINCT subject.*
FROM subject 
INNER JOIN teacher_teaches_subjects_in_groups USING(subject_number)
INNER JOIN student_group USING(group_number)
WHERE student_group.speciality = 'АСОИ'

--7. get information about teachers who teach subjects in the specialty of ASOI
SELECT DISTINCT teacher.*
FROM teacher
INNER JOIN teacher_teaches_subjects_in_groups USING(personal_number)
INNER JOIN student_group USING(group_number)
WHERE student_group.speciality = 'АСОИ'

--8. get the names of teachers who teach subjects in 210 classrooms.
SELECT DISTINCT surname 
FROM teacher
INNER JOIN teacher_teaches_subjects_in_groups USING(personal_number)
WHERE audience_number = 210

--9. get the names of subjects and the names of groups that teach classes in classrooms from 100 to 200.
SELECT subject_name, student_group.group_name
FROM subject
INNER JOIN teacher_teaches_subjects_in_groups USING(subject_number)
INNER JOIN student_group USING(group_number)
WHERE teacher_teaches_subjects_in_groups.audience_number BETWEEN 100 AND 200

--10. Get pairs of group numbers from the same specialty.
SELECT num1.group_number AS `first`, num2.group_number AS `second`
FROM student_group AS num1 INNER JOIN student_group AS num2 ON num1.group_number != num2.group_number
INNER JOIN student_group AS num11 ON num11.group_number = num1.group_number
INNER JOIN student_group AS num22 ON num22.group_number = num2.group_number
WHERE (num11.speciality = num22.speciality AND num11.group_number < num22.group_number);


--11. find the total number of student with ECM speciality
SELECT SUM(number_of_people)
FROM student_group
WHERE speciality = 'ЭВМ'

--12. get the numbers of teachers teaching students in the ECM specialty.
SELECT personal_number
FROM teacher
INNER JOIN teacher_teaches_subjects_in_groups USING(personal_number)
INNER JOIN student_group USING(group_number)
WHERE student_group.speciality = 'ЭВМ'

--13. get number of the subjects that are studied by all groups
SELECT subject_number
FROM teacher_teaches_subjects_in_groups
GROUP BY subject_number
HAVING COUNT(group_number) = (
  SELECT COUNT(DISTINCT group_number)
  FROM teacher_teaches_subjects_in_groups
)

--14. get the names of teachers teaching the same subjects as the teacher teaching the subject with the number 14P
SELECT DISTINCT surname
FROM teacher
INNER JOIN teacher_teaches_subjects_in_groups USING(personal_number)
WHERE subject_number IN (
  SELECT DISTINCT subject_number
  FROM teacher_teaches_subjects_in_groups
  WHERE personal_number = (
    SELECT DISTINCT personal_number
    FROM teacher_teaches_subjects_in_groups
    WHERE subject_number = '14П'
  )
)

--15. Get information about subjects that are not taught by a teacher with a personal number 221P 
SELECT DISTINCT subject.*
FROM subject
INNER JOIN teacher_teaches_subjects_in_groups USING(subject_number)
WHERE subject_number NOT IN (
  SELECT DISTINCT subject_number
  FROM teacher_teaches_subjects_in_groups
  WHERE personal_number = '221Л'
)

--16. get information about subjects that are not studied by M-6 group
SELECT DISTINCT subject.*
FROM subject
INNER JOIN teacher_teaches_subjects_in_groups USING(subject_number)
WHERE subject_number NOT IN (
  SELECT DISTINCT subject_number
  FROM teacher_teaches_subjects_in_groups
  INNER JOIN student_group USING(group_number)
  WHERE student_group.group_name = 'М-6'
)

--17. get information about docents that are teach in '3Г' and '8Г' groups
SELECT DISTINCT teacher.*
FROM teacher 
INNER JOIN teacher_teaches_subjects_in_groups USING(personal_number)
WHERE position = 'Доцент' AND
      teacher_teaches_subjects_in_groups.group_number IN ('3Г', '8Г')
      
--18. get the numbers of subjects, numbers of teachers, numbers of groups in which teachers from the computer department with the specialty of ASOI teach classes
SELECT subject_number, personal_number, group_number
FROM teacher_teaches_subjects_in_groups
INNER JOIN teacher USING(personal_number)
INNER JOIN student_group USING(group_number)
WHERE CHARINDEX(teacher.department, 'ЭВМ') != 0 AND
	  student_group.speciality = 'АСОИ'
	  
--19. get group number with same speciality as they teachers have
SELECT DISTINCT group_number
FROM student_group
INNER JOIN teacher_teaches_subjects_in_groups USING(group_number)
INNER JOIN teacher USING(personal_number)
WHERE CHARINDEX(student_group.speciality, teacher.speciality) != 0

--20. get the numbers of teachers from the computer department who teach subjects in the specialty that coincides with the specialty of the student group
SELECT DISTINCT personal_number
FROM teacher
INNER JOIN teacher_teaches_subjects_in_groups USING(personal_number)
INNER JOIN subject USING(subject_number)
INNER JOIN student_group USING(group_number)
WHERE teacher.department = 'ЭВМ' AND
	  subject.speciality = student_group.speciality
	  
--21. get the specialties of the student group, where the teachers of the ACS department work
SElECT DISTINCT student_group.speciality
FROM student_group
INNER JOIN teacher_teaches_subjects_in_groups USING(group_number)
INNER JOIN teacher USING(personal_number)
WHERE teacher.department = 'АСУ'

--22. get subject numbers that are taught by 'АС-8' group
SELECT subject_number
FROM teacher_teaches_subjects_in_groups
INNER JOIN student_group USING(group_number)
WHERE student_group.group_name = 'АС-8'

--23. get the numbers of student groups that study the same subjects as the AC-8 student group
SELECT DISTINCT group_number
FROM teacher_teaches_subjects_in_groups
WHERE subject_number IN (
  SELECT subject_number
  FROM teacher_teaches_subjects_in_groups
  INNER JOIN student_group USING(group_number)
  WHERE student_group.group_name = 'АС-8'
) AND group_number != (
  SELECT group_number
  FROM student_group
  WHERE group_name = 'АС-8'
)

--24. get the numbers of student groups that study the same subjects as the AC-8 student group
SELECT group_number
FROM teacher_teaches_subjects_in_groups
WHERE group_number NOT IN 
(
SELECT DISTINCT group_number
FROM teacher_teaches_subjects_in_groups
WHERE subject_number IN (
  SELECT subject_number
  FROM teacher_teaches_subjects_in_groups
  INNER JOIN student_group USING(group_number)
  WHERE student_group.group_name = 'АС-8'
)
)

--25. get the numbers of student groups that do not study the subjects taught by the teacher 430L.
SELECt group_number
FROM teacher_teaches_subjects_in_groups
EXCEPT 
SELECT group_number
FROM teacher_teaches_subjects_in_groups
WHERE personal_number = '430Л'

--26. get the numbers of teachers working with the E-15 group, but not teaching the 12P subject.
SELECT DISTINCT personal_number
FROM teacher_teaches_subjects_in_groups
INNER JOIN student_group USING(group_number)
WHERE student_group.group_name = 'Э-15' 
EXCEPT
SELECT personal_number
FROM teacher_teaches_subjects_in_groups
WHERe subject_number = '12П'
