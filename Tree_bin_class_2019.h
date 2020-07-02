#pragma once
using namespace BinTrees;
class Tree {
private:
	int info;
	Tree* left;
	Tree* right;
	void draw_img(Tree* root, PictureBox^ px, Graphics^ graph, Pen^ pen, int x, int y, int x1, int y1, int x2, int y2, int n = 0);
public:
	Tree* insert_tree(Tree* root, Tree* r, int info);
	Tree* del_tree(Tree* root, int key);
	void travel(String^& str);
	void sum(Tree* root, int& n);
	void draw_tree(PictureBox^ x, Tree* root);
	void search(Tree* root, int n, bool& h);
	Tree* del_all_tree(Tree* root);
};
Tree* Tree::insert_tree(Tree* root, Tree* r, int info) {
	if (!r) {
		r = new Tree;
		r->left = nullptr;
		r->right = nullptr;
		r->info = info;
		if (!root)return r;
		if (info < root->info) {
			root->left = r;
		}
		else {
			root->right = r;
		}
		return r;
	}
	if (info < r->info) {
		insert_tree(r, r->left, info);
	}
	else {
		insert_tree(r, r->right, info);
	}
	return root;
}
Tree* Tree::del_tree(Tree* root, int key) {
	Tree* p, * p2;
	if (!root) return root;
	if (root->info == key) {
		if (root->left == root->right) {
			delete(root);
			return 0;
		}
		else if (root->left == nullptr) {
			p = root->right;
			delete(root);
			return p;
		}
		else if (root->right == nullptr) {
			p = root->left;
			delete(root);
			return p;
		}
		else {
			p2 = root->right;
			p = root->right;
			while (p->left) {
				p = p->left;
			}
			p->left = root->left;
			delete(root);
			return p2;
		}
	}
	if (root->info < key) root->right = del_tree(root->right, key);
	else root->left = del_tree(root->left, key);
	return root;

}
void Tree::travel(String^& str) {
	Tree* temp = this;
	if (temp) {
		str += (Convert::ToString(temp->info) + " ");
		temp->left->travel(str);
		temp->right->travel(str);
	}
	else {
		return;
	}
}
void Tree::sum(Tree* root, int& n) {
	if (root) {
		n = n + root->info;
		sum(root->left, n);
		sum(root->right, n);
	}
	else {
		return;
	}
}
void Tree::draw_tree(PictureBox^ x, Tree* root) {
	Bitmap^ bmp;//холст
    Graphics^ graph;//кисть
	Pen^ pen;//чёрный карандаш
	bmp = gcnew Bitmap(x->Width, x->Height);
	graph = Graphics::FromImage(bmp);
	pen = gcnew Pen(Color::Black, 2);
	x->Image = bmp;
	draw_img(root, x, graph, pen, x->Width / 2, 50, 0, 0, 0, 0);
}
void Tree::search(Tree* root, int n, bool& h) {
	if (root) {
		if (n == root->info) {
			h = true;
		}
		search(root->left, n, h);
		search(root->right, n, h);
	}
	else {
		return;
	}
}
void Tree::draw_img(Tree* root, PictureBox^ px, Graphics^ graph, Pen^ pen, int x, int y, int x1, int y1, int x2, int y2, int n) {
	if (root) {
		int s = 70;
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 14);
		Brush^ brush = gcnew SolidBrush(Color::Red);
		if (n == 0) {
			graph->DrawRectangle(pen, x, y, 40, 40);
			graph->DrawString(Convert::ToString(root->info), drawFont, brush, x+10, y+10 );
			x1 = x;
			y1 = y;
		}
		if (n == 1) {
			graph->DrawLine(pen, x1, y1, x2, y2);
			graph->DrawLine(pen, x2, y2, x2 + 6, y2);
			graph->DrawLine(pen, x2, y2, x2, y2 - 6);
			graph->DrawRectangle(pen, x, y, 40, 40);
			graph->DrawString(Convert::ToString(root->info), drawFont, brush, x + 10, y+10);
			x1 = x;
			y1 = y;
			s = 0;
		}
		if (n == 2) {
			graph->DrawLine(pen, x1, y1, x2, y2);
			graph->DrawLine(pen, x2, y2, x2, y2 -6);
			graph->DrawLine(pen, x2, y2, x2 - 6, y2);
			graph->DrawRectangle(pen, x, y, 40, 40);
			graph->DrawString(Convert::ToString(root->info), drawFont, brush, x+10, y+10);
			x1 = x;
			y1 = y;
			s = 0;
		}
		draw_img(root->left, px, graph, pen, x - 50 - s, y + 50, x1, y1 + 40, x1 - 10 - s, y1 + 50, 1);
		draw_img(root->right, px, graph, pen, x + 50 + s, y + 50, x1 + 40, y1 + 40, x1 + 50 + s, y1 + 50, 2);
		
	}
	else {
		return;
	}
}
Tree* Tree::del_all_tree(Tree* root) {
	Tree* p, * p2;
	if (!root) return root;
	if (root->left == root->right) {
		delete(root);
		return 0;
	}
	else if (root->left == nullptr) {
		p = root->right;
		delete(root);
		return p;
	}
	else if (root->right == nullptr) {
		p = root->left;
		delete(root);
		return p;
	}
	else {
		p2 = root->right;
		p = root->right;
		while (p->left) {
			p = p->left;
		}
		p->left = root->left;
		delete(root);
		return p2;
	}
	root->right = del_all_tree(root->right);
	root->left = del_all_tree(root->left);
	return root;
}

