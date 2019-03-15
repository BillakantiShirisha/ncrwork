use practice;

CREATE TABLE dept(
  deptno int,
  dname  nVARCHAR(14),
  loc    nVarchar(13),
  CONSTRAINT pk_dept PRIMARY KEY (deptno));

CREATE TABLE emp(
  empno    int,
  ename    nVARCHAR(10),
  job      nVARCHAR(9),
  mgr      INT,
  hiredate DATE,
  sal      DECIMAL(7,2),
  comm     DECIMAL(7,2),
  deptno   INT,
  CONSTRAINT pk_emp PRIMARY KEY (empno),
  constraint fk_deptno foreign key (deptno) references dept(deptno)
);

CREATE TABLE salgrade(
  grade int,
  losal int,
  hisal int
);

INSERT INTO emp VALUES(
 7839, 'KING', 'PRESIDENT', null,
 convert(datetime,'1981-11-17'),
 5000, null, 10);

INSERT INTO emp VALUES(
 7698, 'BLAKE', 'MANAGER', 7839,
 ('1-5-1981'),
 2850, null, 30);

INSERT INTO emp VALUES(
 7782, 'CLARK', 'MANAGER', 7839,
 '9-6-1981',
 2450, null, 10);

INSERT INTO emp VALUES(
 7566, 'JONES', 'MANAGER', 7839,
 ('2-4-1981'),
 2975, null, 20);

INSERT INTO emp VALUES(
 7788, 'SCOTT', 'ANALYST', 7566,
('13-JUL-87'),
 3000, null, 20);

INSERT INTO emp VALUES(
 7902, 'FORD', 'ANALYST', 7566,
('3-12-1981'),
 3000, null, 20 );

INSERT INTO emp VALUES(
 7369, 'SMITH', 'CLERK', 7902,
 convert(datetime,'1980-12-17'),
 800, null, 20 );

INSERT INTO emp VALUES(
 7499, 'ALLEN', 'SALESMAN', 7698,
 ('1981-2-20'),
 1600, 300, 30);

INSERT INTO emp VALUES(
 7521, 'WARD', 'SALESMAN', 7698,
 ('1981-2-22'),
 1250, 500, 30 );

INSERT INTO emp VALUES(
 7654, 'MARTIN', 'SALESMAN', 7698,
 ('1981-9-28'),
 1250, 1400, 30 );

INSERT INTO emp VALUES(
 7844, 'TURNER', 'SALESMAN', 7698,
 ('1981-8-9'),
 1500, 0, 30);

INSERT INTO emp VALUES(
 7876, 'ADAMS', 'CLERK', 7788,
 ('13-JUL-87'),
 1100, null, 20 );

INSERT INTO emp VALUES(
 7900, 'JAMES', 'CLERK', 7698,
 ('3-12-1981'),
 950, null, 30 );

INSERT INTO emp VALUES(
 7934, 'MILLER', 'CLERK', 7782,
 ('1982-1-23'),
 1300, null, 10 );

INSERT INTO dept VALUES(10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO dept VALUES(20, 'RESEARCH', 'DALLAS');
INSERT INTO dept VALUES(30, 'SALES', 'CHICAGO');
INSERT INTO dept VALUES(40, 'OPERATIONS', 'BOSTON');

INSERT INTO salgrade VALUES (1, 700, 1200);
INSERT INTO salgrade VALUES (2, 1201, 1400);
INSERT INTO salgrade VALUES (3, 1401, 2000);
INSERT INTO salgrade VALUES (4, 2001, 3000);
INSERT INTO salgrade VALUES (5, 3001, 9999);

1. select * from emp where sal between 1000 and 2000;

2. select deptno,dname from dept order by dname;

3. select distinct(job) from emp;

4. select * from emp where deptno in(10,20) order by ename;

5. select ename,job from emp where deptno=20 and job='CLERK';

6. select ename from emp where ename like '%TH%' or ename like '%LL%';

7. select * from emp where mgr is null;

8. select ename,sal+isnull(comm,0)Remuneration from emp;

9. select ename,12*sal,comm from emp where sal>isnull(comm,0) order by sal desc,ename desc;

10. select ename,round(sal+sal*0.15,2),concat(ename,job) "EName + Job" from emp;

11. select job as "Salesperson" from emp where job='SALESMAN' and deptno=30;

11. update emp set job='SALESPERSON' from emp where job='SALESMAN' and deptno=30;

12. select min(sal)"MINIMUM SAL",max(sal)"MAXIMUM SAL",job from emp group by job; 

13. select count(distinct(mgr)) from emp;

14. select avg(sal)"AVERAGE SAL",sum(sal+isnull(comm,0))"REMUNERATION",job from emp group by job;

15. select max(sal),min(sal),max(sal)-min(sal)"DIFFERENCE" from emp;

16. select deptno,count(*) from emp group by deptno having count(*)>3;

17. select count(empno),count(*) from emp;

18. select * from emp where sal in(select min(sal) from emp group by mgr having min(sal)<1000) and mgr is not null order by sal;

19. select ename,dname from emp,dept where emp.deptno=dept.deptno order by dname;

20. select ename,emp.deptno,dname from emp,dept where dept.deptno=emp.deptno;

21. select ename,location,dname,sal from emp,dept where dept.deptno=emp.deptno and sal>1500;

22. select ename,sal,grade from emp,salgrade where sal between losal and hisal and grade=3;

23. select ename,location from emp,dept where dept.deptno=emp.deptno and location ='DALLAS';

24. select ename,job,sal,grade,dname from emp,salgrade,dept where dept.deptno=emp.deptno and sal between losal and hisal and job!='CLERK' order by sal desc;

25. select *from emp where sal*12=36000 or job='CLERK';

26. select dname,deptno from dept where deptno not in(select deptno from emp);

/*select job,max(sal) HighestSal from emp group by job;*/

27. select *from emp e where sal=(select max(sal) from emp where e.job=emp.job);

28. select max(hiredate) Recent,deptno from emp group by deptno order by Recent;

29. select count(*) coun,sum(sal) total,avg(sal) average,deptno from emp group by deptno;

select * from emp;

select * from dept;

select * from salgrade;