--CREATE DATABASE StudentCourse
--USE StudentCourse
--CREATE TABLE Student
--(
--	ѧ�� CHAR(6) PRIMARY KEY,
--	���� CHAR(12) NOT NULL,
--	רҵ�� VARCHAR(20),
--	�Ա� CHAR(2) NOT NULL,
--	����ʱ�� CHAR(2) NOT NULL,
--	��ѧ�� INT,
--	��ע TEXT
--)
--GO

---- ��StudentCourse���ݿ��д���Course��
--USE StudentCourse
----CREATE TABLE <TABLE_NAME>
--CREATE TABLE Course
--(
--	�γ̺� CHAR(4) NOT NULL PRIMARY KEY,
--	�γ��� VARCHAR(40) NOT NULL,
--	��ѧ���� INT,
--	ѧʱ INT,
--	ѧ�� INT,
--)

USE StudentCourse
CREATE TABLE StuCourse
(
	ѧ�� char(6) not null,
	--  ͬʱ��ѧ�š��γ̺�����Ϊ����
	�γ̺� char(4) not null primary key(ѧ��, �γ̺�),
	�ɼ� real,
)

--ʹ��sa�û���½���Ƚ�sa���ã����������룬�ٽ����ݿ�����Ϊ��windows��sqlserver��ݵ�½
--
--