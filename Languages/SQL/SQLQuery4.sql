--Use StudentCourse
--IF EXISTS(SELECT name FROM sysindexes WHERE name = 'CourseNo_ind')
--DROP INDEX Course.CourseNo_ind
--GO
--CREATE INDEX CourseNo_ind ON Course(�γ̺�)
--GO

--USE StudentCourse
--DROP INDEX Course.CourseNo_ind
--GO

USE StudentCourse
EXEC sp_helpindex Student
GO

