#include "objloader.h"

#include <QFile>
#include <QTextStream>

ObjLoader::ObjLoader(void)
{
}

ObjLoader::~ObjLoader(void)
{
}

bool ObjLoader::load( const QString filename, Object *object )
{
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}
	QTextStream in(&file);

	QString line;
	float f1 = 0, f2 = 0, f3 = 0;
	Object::Group *group;
	while (!in.atEnd())
	{
		line = in.readLine();

		if (line.length() == 0 ||
			line[0] == '#')
		{
			continue;
		}
		line = line.simplified();
		QStringList strs = line.split(' ');
		if (strs.count() == 0)
		{
			continue;
		}
		QString flag = strs[0];
		if (flag[0] == 'v')
		{
			if (strs.count() < 3)
			{
				continue;
			}
			f1 = strs[1].toFloat();
			f2 = strs[2].toFloat();
			if (flag.length() == 1 && strs.count() > 3)
			{
				f3 = strs[3].toFloat();
				object->addVertex(QVector3D(f1, f2, f3));
			}
			else if (flag[1] == 'n' && strs.count() > 3)
			{
				f3 = strs[3].toFloat();
				object->addNormal(QVector3D(f1, f2, f3));
			}
			else if (flag[1] == 't')
			{
				object->addTexture(QVector2D(f1, f2));
			}
		}
		else if (flag[0] == 'f')
		{
			if (strs.count() < 4)
			{
				continue;
			}
			Object::TriangleFace f;
			f.hasN = true;
			f.hasT = true;
			if (strs[1].contains("//")) // v//n 
			{
				f.hasT = false;
				for (int i = 1; i <= 3; i++)
				{
					QStringList substrs = strs[i].split("//");
					f.v[i - 1] = substrs[0].toInt() - 1;	// because the start of index is 1 in obj file
					f.t[i - 1] = 0;
					f.n[i - 1] = substrs[1].toInt() - 1;
				}
			}
			else if (strs[1].contains(QRegExp("\\d+/\\d+/\\d+"))) // v/t/n
			{
				for (int i = 1; i <= 3; i++)
				{
					QStringList substrs = strs[i].split("/");
					f.v[i - 1] = substrs[0].toInt() - 1;
					f.t[i - 1] = substrs[1].toInt() - 1;
					f.n[i - 1] = substrs[2].toInt() - 1;
				}
			}
			else if (strs[1].contains(QRegExp("\\d+/\\d+"))) // v/t
			{
				f.hasN = false;
				for (int i = 1; i <= 3; i++)
				{
					QStringList substrs = strs[i].split("/");
					f.v[i - 1] = substrs[0].toInt() - 1;
					f.t[i - 1] = substrs[1].toInt() - 1;
					f.n[i - 1] = 0;
				}
			}
			else // v
			{
				f.hasT = false;
				f.hasN = false;
				for (int i = 1; i <= 3; i++)
				{
					f.v[i - 1] = strs[i].toInt() - 1;
					f.t[i - 1] = 0;
					f.n[i - 1] = 0;
				}
			}
			object->addFace(f);
			group->tIndices.append(object->facesNum() - 1);
		}
		else if (flag[0] == 'g')
		{
			Object::Group newgroup;
			newgroup.name = strs.count() > 1 ? strs[1] : "";
			group = object->addGroup(newgroup);
		}
		else if (flag[0] == 'm')
		{
			object->setMtlLibName(strs[1]);
			//loadmtl
		}
		/* for material
		else if (flag[0] == 'u')
		{

		}*/
	}
	object->adjust();

	file.close();

	return true;
}
