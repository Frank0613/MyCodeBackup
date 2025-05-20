use `First_Database`;
set sql_safe_updates = 0;
create table `student_data`(
	`student_id` int primary key auto_increment, -- auto_increment會自己+1
    `name` varchar(20) unique, 
    `major` varchar(20) not null,  
    `score` int default 0
);
insert into `student_data`(`major`,`name`,`score`) values('音樂','道申',100);
insert into `student_data`(`major`,`name`,`score`) values('美術','莉榛',100);
insert into `student_data`(`major`,`name`,`score`) values('設計','女人',80);
insert into `student_data`(`major`,`name`,`score`) values('互動','男人',60);
insert into `student_data`(`major`,`name`,`score`) values('國文','子貴',40);

select * from `student_data`; -- 顯示(*指所有)

select `name` 
from `student_data`
where `major` in('互動' , '設計'); -- 或是的意思

select *
from `student_data`
where `score` >= 60;
