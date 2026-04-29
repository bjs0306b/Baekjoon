
import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);
	@SuppressWarnings("unchecked")
	static ArrayList<Integer>[][] bcs = new ArrayList	[10][10];
	static int m,n;
	static int[] A,B;
	static int[] dx= new int[] {0,-1,0,1,0}, dy = new int[] {0,0,1,0,-1};
	static int[] ps;
	
	static void fill_sc(int x, int y, int c, int p, int idx) {
		for(int i=x-c;i<=x+c;i++) {
			for(int j=y-c;j<=y+c;j++) {
				if(!(i >= 0 && i < 10 && j >= 0 && j < 10)) continue;
				if(Math.abs(i-x) + Math.abs(j-y) <= c) {
					bcs[i][j].add(idx);
				}
			}
		}
	}
	
	static void input() {
		m = sc.nextInt();
		n = sc.nextInt();
		A = new int[m];
		B = new int[m];
		ps = new int[n+1];
		for(int i=0;i<10;i++) for(int j=0;j<10;j++) bcs[i][j] = new ArrayList<Integer>();
		for(int i=0;i<m;i++) A[i] = sc.nextInt();
		for(int i=0;i<m;i++) B[i] = sc.nextInt();
		for(int i=0;i<n;i++) {
			int x,y,c,p;
			x = sc.nextInt();
			y = sc.nextInt();
			c = sc.nextInt();
			p = sc.nextInt();
			ps[i] = p;
			fill_sc(y-1,x-1,c,p,i);
		}
	}
	
	static int cal_mx_p(int ax, int ay, int bx, int by) {
		int ret = 0;
		if(bcs[ax][ay].size() > 0 && bcs[bx][by].size() > 0) {
			for(int i=0;i<bcs[ax][ay].size();i++) {
				for(int j=0;j<bcs[bx][by].size();j++) {
					int a = bcs[ax][ay].get(i), b = bcs[bx][by].get(j);
					if(a == b) {
						ret = Math.max(ret, ps[a]);
					}
					else {
						ret = Math.max(ret,  ps[a] + ps[b]);
					}
				}
			}
		}
		else {
			int amx = 0, bmx = 0;
			for(int i=0;i<bcs[ax][ay].size();i++) amx = Math.max(amx, ps[bcs[ax][ay].get(i)]);
			for(int i=0;i<bcs[bx][by].size();i++) bmx = Math.max(bmx, ps[bcs[bx][by].get(i)]);
			ret = Math.max(amx, bmx);
		}
			
		return ret;
	}
	
	static int solve() {
		// 이동 시작
		int ax = 0, ay = 0, bx = 9, by = 9;
		int ret = cal_mx_p(ax, ay, bx, by);
		for(int i=0;i<m;i++) {
			//System.out.println(ret);
			ax += dx[A[i]];
			ay += dy[A[i]];
			bx += dx[B[i]];
			by += dy[B[i]];
			ret += cal_mx_p(ax, ay, bx, by);
		}
		return ret;
	}
	
	public static void main(String[] args) {
		int t = sc.nextInt();
		for(int i=1;i<=t;i++) {
			input();
			int ans = solve();
			System.out.println("#" + i + " " + ans);
		}
	}
}
