-- 創建資料庫
create database `Company`;
use `Company`;
show databases;

-- 創建員工表格
create table `Employee`(
	`employee_id` int primary key,
    `name` varchar(20),
    `brith_date` date,
    `sex` varchar(5),
    `salary` int,
    `branch_id` int,
	`sup_id` int
);
-- 創建Foreign key
alter table `Employee`
add foreign key(`branch_id`)
references `Branch`(`branch_id`)
on delete set null; -- 當對應不到設成null

alter table `Employee`
add foreign key(`sup_id`)
references `Employee`(`employee_id`)
on delete set null;

-- 創建部門表格
create table `Branch`(
	`branch_id` int primary key,
    `branch_name` varchar(20),
    `manager_id` int,
    foreign key (`manager_id`) references `Employee`(`employee_id`) on delete set null
    
);

-- 創建客戶表格
create table `Client`(
	`client_id` int primary key,
    `client_name` varchar(20),
    `phone_number` varchar(20)
);

-- 創建業績表格
create table `Work_with`(
	`emp_id` int,
    `client_id` int,
    `total_sales` int,
    primary key(`emp_id`,`client_id`),
    foreign key(`emp_id`) references `Employee`(`employee_id`) on delete cascade, -- 注意primary key不可以是null所以不可設定成set null
    foreign key(`client_id`) references `Client`(`client_id`) on delete cascade -- 當對應不到這筆資料跟著刪除
);

-- 顯示 
drop table `Work_with`;
select * from `Employee`;