-- 新增branch資料，因為還沒有employee資料可以給foreign key找，所以先設成null，等employee新增完再改回來
insert into `Branch` value(1,'研發',null);
insert into `Branch` value(2,'行政',null);
insert into `Branch` value(3,'資訊',null);

-- 新增employee資料
insert into `Employee` value(206,'小黃','1998-10-08','F',50000,1,null);
insert into `Employee` value(207,'小綠','1985-09-16','M',29000,2,206);
insert into `Employee` value(208,'小黑','2000-12-19','M',35000,3,206);
insert into `Employee` value(209,'小白','1997-01-22','F',39000,3,207);
insert into `Employee` value(210,'小藍','1925-11-10','F',84000,1,207);

-- 修改branch資料
update `Branch`
set `manager_id` = 208
where `branch_id` = 3;

update `Employee`
set `branch_id` = 2
where `employee_id` = 207;

-- 新增client資料
insert into `Client` value(400,'阿狗',254354335);
insert into `Client` value(401,'阿貓',25633899);
insert into `Client` value(402,'阿雞',453543345);
insert into `Client` value(403,'阿豬',985072184);
insert into `Client` value(404,'阿羊',929302976);

-- 新增Work_with資料
insert into `Work_with` value(206,400,'70000');
insert into `Work_with` value(207,401,'24000');
insert into `Work_with` value(208,402,'9800');
insert into `Work_with` value(209,403,'24000');
insert into `Work_with` value(210,404,'87950');

select * from `Employee`;

