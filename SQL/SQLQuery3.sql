--2.1

select Student.*, �γ̺�, �ɼ� from Student, StuCourse
where Student.ѧ�� = StuCourse.ѧ��

--2.2
select Student.*, �γ̺�, �ɼ� from Student, StuCourse
where Student.ѧ�� = StuCourse.ѧ�� and רҵ�� = '�������ѧ�뼼��'

--2.3

select Student.*, �γ̺�, �ɼ� from Student, StuCourse
where Student.ѧ�� = StuCourse.ѧ�� and �ɼ� < 60

--2.4
select a.*, �γ���, �ɼ� from Student a, StuCourse b, Course c
where a.ѧ�� = b.ѧ�� and b.�γ̺� = c.�γ̺�

--2.5
select a.*, �γ���, �ɼ��ȼ� = 
case
	when �ɼ� >= 90 then '��'
	when �ɼ� >= 80 then '��'
	when �ɼ� >= 70 then '��'
	when �ɼ� >= 60 then '����'
	else '������'
end

from Student a, StuCourse b, Course c
where a.ѧ�� = b.ѧ�� and b.�γ̺� = c.�γ̺�

-- 2.6

select a.*, �γ̺�, �ɼ� 
from Student a LEFT JOIN StuCourse b on a.ѧ�� = b.ѧ��













--3.1
select * from Student
where ����ʱ�� = 
(
	select ����ʱ�� from Student where ���� = '��һƽ'
)


--3.2

select * from Student
	where ѧ�� not in
	(
		select ѧ�� from StuCourse
	)


--3.3
select * from Student where exists
(
	select * from StuCourse a, Course b
	where ѧ�� = a.ѧ�� and a.�γ̺� = b.�γ̺� and �γ��� = '��·����'
)


--3.4

select ѧ��, ���� from Student where ѧ�� in
(
	select ѧ�� from StuCourse x
	where not exists
	(
		select * from StuCourse y
		where y.ѧ�� = '070101' and not exists
		(
			select * from StuCourse z
			where z.ѧ�� = x.ѧ�� and z.�γ̺� = y.�γ̺�
		)
	)
)

--3.5
select * from Student where ѧ�� not in
(
	select ѧ�� from StuCourse where �γ̺� = 
	(
		select �γ̺� from Course where �γ��� = '������ƻ���'
	)
)





























----4.1
--SELECT SUM(ѧʱ) as ��ѧʱ
--from Course

----4.2
--select avg(�ɼ�) as �����רҵѧ��ƽ���ɼ�
--from StuCourse
--where ѧ�� in
--	(
--		select ѧ�� from Student
--			where רҵ��='�������ѧ�뼼��'
--	)

----4.3
--select avg(�ɼ�) as ������Ϣ����רҵ�ߵ���ѧ1�γ̵�ƽ���ɼ�
--from StuCourse
--where �γ̺� = 
--(
--	select �γ̺�
--	from course 
--	where �γ��� = '�ߵ���ѧ 1'
--	and ѧ�� in
--	(
--		select ѧ�� from Student where רҵ�� = '������Ϣ����'
--	)
--)

--4.4
select max(�ɼ�) as '���Ÿ���1��߳ɼ�', min(�ɼ�) as '������Ϣ����1��ͳɼ�'
from StuCourse a, Student b, Course c
where a.�γ̺� = c.�γ̺� and a.ѧ�� = b.ѧ�� and �γ���= '�ߵ���ѧ 1'
and רҵ�� = '������Ϣ����'

--4.5
select count(*) as ������
from Student
where רҵ��= '������Ϣ����'












--SELECT רҵ��, �γ���, avg(�ɼ�) ƽ���ɼ�
--from StuCourse a, Student b, Course c
--where a.�γ̺� = c.�γ̺� and a.ѧ�� = b.ѧ��
--group by רҵ��, �γ���






----select �γ���, count(ѧ��) as 'ѡ������'
--from StuCourse a,Course b
--where a.�γ̺� = b.�γ̺�
--group by �γ���


--SELECT רҵ��, count(ѧ��) ѧ����
--FROM Student
--Group by רҵ��







---- (3)	�����γ̰�ƽ���ɼ��ɸߵ�������
--SELECT �γ̺�, AVG(�ɼ�)
--	FROM StuCourse
--	GROUP BY �γ̺�
--	ORDER BY AVG(�ɼ�) DESC







---- (2)	���������ѧ�뼼��רҵ�ġ�������ƻ������γ̰��ճɼ��ɸߵ�������
--SELECT a.ѧ��, ����, �ɼ�
--	FROM StuCourse a, Student b, Course c
--	WHERE a.ѧ��=b.ѧ�� AND a.�γ̺� = c.�γ̺� AND �γ���='������ƻ���'
--	ORDER BY �ɼ� DESC



--SELECT * FROM Student;

--��ѯÿ��ѧ����רҵ�����ܷ���
--SELECT רҵ��, ��ѧ�� FROM Student;

--(3)	��ѯѧ��Ϊ��070101��ѧ����������רҵ����
-- SELECT <COLUMNS_NAME> FROM <TABLE_NAME> WHERE <CONDITION>
--SELECT ����, רҵ�� FROM Student WHERE ѧ��='070101';


--4 �������е�רҵ��
--DISTINCTȥ�أ���
-- SELECT DISTINCT <COLUMN_NAME>

--SELECT DISTINCT רҵ�� FROM Student;
--select distinct ���� FROM STUDENT;
--SELECT רҵ�� FROM STUDENT;


--(5)	��ѯStudent���м������ѧ�뼼��רҵѧ����ѧ�š���������ѧ�֣�
-- ����������еı���ֱ�ָ��Ϊnumber��name��mark
--SELECT ѧ�� AS NUMBER, ���� AS NAME, ��ѧ�� AS MARK 
--	FROM STUDENT WHERE רҵ��='�������ѧ�뼼��';

--��AS�����滻��ͷ

--select ѧ��, ����, ��ѧ�� FROM STUDENT WHERE רҵ��='�������ѧ�뼼��';



--(6)	�ҳ�������1989������ġ�������Ϣ���̡�רҵѧ������Ϣ��
--ʱ�����ͼӵ�����
--SELECT * FROM STUDENT WHERE ����ʱ�� BETWEEN '1989-1-1' AND '1989-12-31' AND רҵ��='������Ϣ����';

-- �ҳ�����������ѧ����Ϣ
-- WHERE <COLUNS_NAME> LIKE <CONDITION_NAME_%>
--SELECT * FROM STUDENT WHERE ���� LIKE '��%';




--(1)	����ƽ���ɼ���85������ѧ����ѧ�ź�ƽ���ɼ�
--SELECT ѧ��, AVG(�ɼ�)AS'ƽ���ɼ�'
--	FROM STUCOURSE GROUP BY ѧ�� HAVING AVG(�ɼ�) >= 85;

-- ����ѡ����������3�˵Ŀγ�����ѡ��������
--SELECT �γ���, COUNT(ѧ��)AS'ѡ������'
--	FROM STUCOURSE  a, COURSE b
--	WHERE a.�γ̺� = b.�γ̺�
--	GROUP BY �γ���
--	HAVING COUNT(ѧ��) > 3;


-- (1)	��ѧ�����ݰ�����ʱ������
--SELECT * FROM STUDENT ORDER BY ����ʱ��;

-- (2)	���������ѧ�뼼��רҵ�ġ�������ƻ������γ̰��ճɼ��ɸߵ�������

--SELECT a.ѧ��, ����, �ɼ�
--	FROM STUCOURSE 
--	WHERE a.ѧ�� = b.ѧ�� AND a.�γ̺� = c.�γ̺� AND �γ��� = '������ƻ���' 
--	ORDER BY �ɼ�DESC;


























--CREATE TABLE Student
--(
--	ѧ�� CHAR(6) PRIMARY KEY,
--	���� CHAR(12) NOT NULL,
--	רҵ�� VARCHAR(20),
--	�Ա� CHAR(2) NOT NULL,
--	����ʱ�� SMALLDATETIME NOT NULL,
--	��ѧ�� INT,
--	��ע TEXT
--)

--INSERT INTO Student VALUES('070101', '��һƽ','�������ѧ�뼼��', '��', '1989-5-1', 80, '������');

--INSERT INTO Student VALUES('070102', '����','�������ѧ�뼼��', 'Ů', '1988-12-20', 80, NULL);

--INSERT INTO Student VALUES('070105', '�콭','�������ѧ�뼼��', '��', '1990-1-10', 78, '�в�����Ŀ');

--INSERT INTO Student VALUES('070201', '������','������Ϣ����', 'Ů', '1988-11-19', 74, NULL);

--INSERT INTO Student VALUES('070202', '����','������Ϣ����', '��', '1989-2-18', 74, '��λ�ý�ѧ��');

--INSERT INTO Student VALUES('070206', '�Ժ���','������Ϣ����', '��', '1989-3-20', 72, NULL);

--INSERT INTO Student VALUES('070207', '��ƽƽ','������Ϣ����', 'Ů', '1990-1-10', 74, NULL);

--INSERT INTO Student VALUES('070208', '���','������Ϣ����', '��', '1989-9-12', 74, NULL);

--SELECT * FROM STUDENT;