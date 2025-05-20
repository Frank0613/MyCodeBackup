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

drop table `student_data`; -- 刪除 
select * from `student_data`; -- 顯示

-- 修改
update `student_data`
set `major` = '英文' -- 結果(如果沒有條件會覆蓋所有)
where `major` = '國文'; -- 條件

-- 合併 
update `student_data`
set `major` = '互動設計' -- 結果(如果沒有條件會覆蓋所有)
where `major` = '互動' or `major` = '設計'; -- 條件

-- 刪除
delete from `student_data`
where `major` = '互動設計' and `name` = '女人';

delete from `student_data`
where `score` <= '60';