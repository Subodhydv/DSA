SELECT p.product_name , s.year, s.price from 
Sales s inner join
Product p ON
S.product_id=p.product_id;