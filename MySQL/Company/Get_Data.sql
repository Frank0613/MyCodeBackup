select * from `Employee`;
select * from `Client`;

select * 
from `Employee`
order by `salary` desc -- 排序(desc是高到低，預設低到高)
;

select * 
from `Employee`
order by `salary` desc limit 3 -- limit限制
;