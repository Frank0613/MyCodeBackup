-- wildcards 萬用字元 % 代表多個字元, _ 代表一個字元

-- 取得電話號碼尾數是 ???
select *
from `client`
where `phone_number` like '%354%'; -- %543是尾巴，543%是開頭，%543%是中間有就好

-- 取得名字是 ???
select *
from `client`
where `client_name` like '_豬';

-- 取得12月生日
select *
from `Employee`
where `brith_date` like '_____12%'; -- 五個空格 後月份 後面隨便