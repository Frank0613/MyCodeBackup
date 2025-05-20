-- 員工人數
select count(*) from `Employee`;

-- 出生於1970-01-01後的女生有幾個
select count(*) 
from `Employee`
where `brith_date` >= '1970-01-01' and `sex` = 'F'
;

-- 員工薪水平均
select avg(`salary`) from `Employee`;

-- 員工薪水總和
select sum(`salary`) from `Employee`;

-- 員工最高薪水
select max(`salary`) from `Employee`;

-- 員工最低薪水
select min(`salary`) from `Employee`;
