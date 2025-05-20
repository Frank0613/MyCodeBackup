create database `First_Database`; /*新增資料庫*/
show databases; /*顯示資料庫*/
/*刪除資料庫 --> drop database `First_Database`;*/
use `First_Database`;

/*新增表格*/
create table `student_data`(
	`student_id` int primary key,
    `name` varchar(20),
    `major` varchar(20)
);
/*顯示表格*/
describe `student_data`;
/*刪除表格 --> drop table `student_data`;*/

/*新增、刪除屬性*/
alter table `student_data` add gpa decimal(3,2);
alter table `student_data` drop column gpa;
