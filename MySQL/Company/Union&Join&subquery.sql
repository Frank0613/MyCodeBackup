-- Union 聯集(把結果合併在一起) 對應數量要一樣、資料型態也要一樣

-- 員工名字 union 客戶名字 
select `name` 
from `Employee`
union
select `client_name` 
from `Client`;

-- 員工id + 員工名字 union 客戶id + 客戶名字
select `name`, `employee_id` as `id` -- as 可以改標題名稱
from `Employee`
union
select `client_name`, `client_id`
from `Client`;

-- 員工薪水 union 銷售金額
select `salary` -- as 可以改標題名稱
from `Employee`
union
select `total_sales`
from `Work_with`;

-- join 連結(把表格合併在一起) 可以設定條件

-- 取得所有部門經理的名字
select `employee_id`, `Employee`.`name` , `branch_name` -- 怕屬性名稱重複，可以在前面加上 表格名稱.屬性 
from `Employee` left join `Branch` -- join：連接， left join、right join：左或右不管條件全部回傳
on `employee_id` = `manager_id`; -- 條件 

-- subquery 子查詢 (在搜尋的條件放上搜尋結果)

-- 研發部門經理名字
select `name`
from `Employee`
where`employee_id` = (
	select `manager_id`
	from `Branch`
	where `branch_name` = '研發');

-- 對單一客戶銷售金額超過50000
select `name`
from `Employee`
where `employee_id` in ( -- 很多筆用 in 
	select `emp_id` 
	from `Work_with`
	where `total_sales` >= 50000
);


