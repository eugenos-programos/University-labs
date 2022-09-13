--get data about all teachers
SELECT * FROM teacher;

--get data abount all student groups where speciality is ECM 
SELECT * FROM student_group
WHERE speciality = 'ЭВМ';

--get teacher personal key number and audience number where subject with number '18П' is taught
SELECT personal_number, audience_number
FROM teacher_teaches_subjects_in_groups
WHERE subject_number = '18П'


