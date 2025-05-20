
use `First_Database`;

create table `student_data`(
	`student_id` int primary key,
    `name` varchar(20) default '數學', -- 設定預設值
    `major` varchar(20) not null unique -- 設定條件(不能是null(not null)跟不能重複(unique))
);
drop table `student_data`;
select * from `student_data`; -- 顯示表格裡的資料

insert into `student_data` values(1,'道申',"音樂");
insert into `student_data` values(2,'莉榛',"美術");
insert into `student_data`(`major`,`name`,`student_id`) values(null,'維廷',3); -- 自由決定輸入順序




